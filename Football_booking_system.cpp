//Football Booking System
#include <iostream> 
#include <iomanip> 
#include <vector> 
using namespace std; 
 
const int MAX_SLOTS = 5;  
 
struct Data { 
    int slot, num; 
    string id, name; 
    Data* next; 
}; 
 
struct FootballTurf { 
    int slot; 
    double price; 
}; 
 
void input(Data*& head, Data*& tail, const vector<FootballTurf>& turfPrices) { 
    Data* n = new Data(); 
    n->next = nullptr; 
 
    cout << "Enter your ID: "; 
    cin >> n->id; 
    cout << "Enter your name: "; 
    cin >> n->name; 
    cout << "Enter your phone number: "; 
    cin >> n->num; 
 
    // Choose a slot available 
    do { 
        cout << "Choose a slot available (1-" << MAX_SLOTS << "): "; 
        cin >> n->slot; 
 
        // Check if the slot is already taken 
        Data* temp = head; 
        while (temp != nullptr) { 
            if (temp->slot == n->slot) { 
                cout << "Slot " << n->slot << " is already taken. Please choose another slot." << endl; 
                break; 
            } 
            temp = temp->next; 
        } 
    } while (n->slot < 1 || n->slot > MAX_SLOTS); 
 
    if (head == nullptr) { 
        n->next = head; 
        head = tail = n; 
    } else { 
        tail->next = n; 
        tail = n; 
    } 
    cout << "Press Y to continue... "; 
} 
 
void cancelBooking(Data*& head) { 
    int slotToCancel; 
    cout << "Enter the slot you want to cancel: "; 
    cin >> slotToCancel; 
 
    Data* current = head; 
    Data* previous = nullptr; 
 
    while (current != nullptr) { 
        if (current->slot == slotToCancel) { 
            if (previous == nullptr) { 
                // If the booking to cancel is the first node 
                head = current->next; 
            } else { 
                // If the booking to cancel is not the first node 
                previous->next = current->next; 
            } 
 
            delete current; 
            cout << "Booking for Slot " << slotToCancel << " has been canceled." << endl; 
            return; 
        } 
 
        previous = current; 
        current = current->next; 
    } 
 
    cout << "Booking for Slot " << slotToCancel << " not found." << endl; 
} 
 
void displayAvailability(const vector<FootballTurf>& turfPrices, const Data* head) { 
    cout << "Available Slots:" << endl; 
    cout << setw(20) << "Slot"; 
    cout << setw(30) << "Time Range"; 
    cout << setw(15) << "Status"; 
    cout << setw(20) << "Price"; 
    cout << endl; 
 
    for (int i = 1; i <= MAX_SLOTS; ++i) { 
        bool slotAvailable = true; 
 
        // Check if the slot is booked 
        const Data* temp = head; 
        while (temp != nullptr) { 
            if (temp->slot == i) { 
                slotAvailable = false; 
                break; 
            } 
            temp = temp->next; 
        } 
 
        // Find the price for the slot 
        double price = 0.0; 
        for (const auto& turf : turfPrices) { 
            if (turf.slot == i) { 
                price = turf.price; 
                break; 
            } 
        } 
 
        cout << setw(20) << "Slot " << i; 
        if (i == 1) { 
            cout << setw(30) << "10:00 AM - 12:00 AM"; 
        } else if (i == 2) { 
            cout << setw(30) << "12:00 PM - 2:00 PM"; 
        } else if (i == 3) { 
            cout << setw(30) << "2:00 PM - 4:00 PM"; 
        } 
        else if (i == 4) { 
            cout << setw(30) << "4:00 PM - 6:00 PM"; 
        } 
        else if (i == 5) { 
            cout << setw(30) << "6:00 PM - 8:00 PM"; 
        } 
         
         
        cout << setw(15) << (slotAvailable ? "Available" : "Booked"); 
        cout << setw(20) << price; 
        cout << endl; 
         
    } 
     
} 
 
void displaySlotInfo(const Data* head, const vector<FootballTurf>& turfPrices) { 
    Data* p = const_cast<Data*>(head); 
  
 
    // Display table header 
    cout << setw(15) << "Slot"; 
    cout << setw(30) << "Time Range"; 
    cout << setw(15) << "Name"; 
    cout << setw(15) << "ID"; 
    cout << setw(20) << "Phone Number"; 
    cout << setw(20) << "Price"; 
    cout << endl;
     
while (p != nullptr){ 
        cout << setw(15) << "Slot " << p->slot; 
        if (p->slot == 1) { 
            cout << setw(30) << "10:00 AM - 12:00 AM"; 
        } else if (p->slot == 2) { 
            cout << setw(30) << "12:00 PM - 2:00 PM"; 
        } else if (p->slot == 3) { 
            cout << setw(30) << "2:00 PM - 4:00 PM"; 
        } 
        else if (p->slot == 4) { 
            cout << setw(30) << "4:00 PM - 6:00 PM"; 
        } 
        else if (p->slot == 5) { 
            cout << setw(30) << "6:00 PM - 8:00 PM"; 
        } 
        cout << setw(15) << p->name; 
        cout << setw(15) << p->id; 
        cout << setw(20) << p->num; 
        // Find data for the current slot 
         
 
               double price = 0.0; 
                for (const auto& turf : turfPrices) { 
                    if (turf.slot == p->slot) { 
                         price = turf.price; 
                break; 
                } 
            } 
                    if (price != 0.0) { 
                        cout << setw(20) << price; 
                    } 
                    else { 
                        cout << setw(20) << "N/A"; 
                    } 
                     
                    p=p->next; 
                    cout<<"\n"; 
} 
   
} 
     
void bubble_sort_slots(Data** head) {
    int swapped;
    Data* ptr1;
    Data* lptr = nullptr;

    // Check if the list is empty
    if (*head == nullptr)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->slot > ptr1->next->slot) {
                // Swap the data of the nodes, not the pointers
                swap(ptr1->slot, ptr1->next->slot);
                swap(ptr1->id, ptr1->next->id);
                swap(ptr1->name, ptr1->next->name);
                swap(ptr1->num, ptr1->next->num);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

 
int main() { 
    char choice; 
    Data* head = nullptr, * tail = nullptr; 
 
    vector<FootballTurf> turfPrices = { 
        {1, 20.0}, 
        {2, 20.0}, 
        {3, 20.0} 
        // ... Add prices for other slots 
    }; 
 
    displayAvailability(turfPrices, head); 
 
    do { 
        cout << "Enter 'B' to book or 'C' to cancel: "; 
        cin >> choice; 
         
 
        if (choice == 'B' || choice == 'b') { 
            input(head, tail, turfPrices); 
            displayAvailability(turfPrices, head); 
             
        } else if (choice == 'C' || choice == 'c') { 
            cancelBooking(head); 
            displayAvailability(turfPrices, head); 
        } 
 
         
        cin.ignore(32767, '\n');  
    } while (choice != 'N' && choice != 'n');  
 
    cout << "\n::Your Booking Detail::\n"; 
    displaySlotInfo(head, turfPrices); 
     
    bubble_sort_slots(&head);
    cout<<"after sorting\n";
    displaySlotInfo(head,turfPrices);
 
    //Cleanup: Deallocate memory for booked slots 
    Data* current = head; 
    while (current != nullptr) { 
        Data* next = current->next; 
        delete current; 
        current = next; 
    } 
       
 
    return 0; 
}