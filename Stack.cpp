#include <iostream>
#include <stack>
using namespace std;

void analysis(stack<int> mystack) {
    if (mystack.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    int evenCount = 0, oddCount = 0;
    int count = 1;

    cout << ":: Analysis ::" << endl;
    while (!mystack.empty()) {
        int val = mystack.top();
        cout << "Value " << count << ": " << val;
        if (val % 2 == 0) {
            cout << " (Even)" << endl;
            evenCount++;
        } else {
            cout << " (Odd)" << endl;
            oddCount++;
        }
        mystack.pop();
        count++;
    }

    cout << "Total even values: " << evenCount << endl;
    cout << "Total odd values: " << oddCount << endl;
}

int main() {
    stack<int> mystack;

    int size, val;

    cout << "Enter total value to insert: ";
    cin >> size;
    for (int i = 1; i <= size; i++) {
        cout << "Enter a value : ";
        cin >> val;
        mystack.push(val);
    }

    cout << "\n::Analysis::" << endl;
    analysis(mystack);

    cout << "\nRemoving all numbers..." << endl;
    while (!mystack.empty()) {
        mystack.pop();
    }
    cout << "[Result] All numbers have been deleted." << endl;

    cout << "\nEnd of program";
    return 0;
}
