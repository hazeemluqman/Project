public class Book {
    private String title;
    private String author;
    private int year;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public static void main(String[] args) {
        
        Book myBook = new Book();

        
        myBook.setTitle("The Great Gatsby");
        myBook.setAuthor("F. Scott Fitzgerald");
        myBook.setYear(1925);

        
        System.out.println("Title: " + myBook.getTitle());
        System.out.println("Author: " + myBook.getAuthor());
        System.out.println("Year: " + myBook.getYear());
    }
}