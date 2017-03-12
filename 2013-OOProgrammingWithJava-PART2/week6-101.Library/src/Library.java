import java.util.ArrayList;

public class Library {
    private ArrayList<Book> library;
    
    public Library(){
        this.library = new ArrayList<Book>();
    }
    
    public void addBook(Book newBook){
        library.add(newBook);
    }
    
    public void printBooks(){
        for(Book book : library){
            System.out.println(book);
        }
    }
    
    public ArrayList<Book> searchByTitle(String title){
        ArrayList<Book> found = new ArrayList<Book>();
        for(Book book: library){
            if(StringUtils.included(book.title(), title)){
            found.add(book);
            }
        }
        return found;
    }
    
    public ArrayList<Book> searchByPublisher(String publisher){
        ArrayList<Book> found = new ArrayList<Book>();
        for(Book book: library){
            if(StringUtils.included(book.publisher(), publisher)){
                found.add(book);
            }
        }
        return found;
    }
    
    public ArrayList<Book> searchByYear(int year){
        ArrayList<Book> found = new ArrayList<Book>();
        for(Book book: library){
            if(book.year() == year){
                found.add(book);
            }
        }
        return found;
    }
}
