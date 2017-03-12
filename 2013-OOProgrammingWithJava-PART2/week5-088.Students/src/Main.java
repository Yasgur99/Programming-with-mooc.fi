
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        ArrayList<Student> list = new ArrayList<Student>();
        String name;
        String studentNumber;
        String searchTerm;

        while (true) {
            System.out.print("name: ");
            name = reader.nextLine();
            if (name.equals("")) {
                break;
            }
            System.out.print("studentnumber: ");
            studentNumber = reader.nextLine();
            list.add(new Student(name, studentNumber));
        }
        
        for(Student student : list){
            System.out.println(student);
        }
        
        System.out.print("Give search term: ");
        searchTerm = reader.nextLine();
        System.out.println("Results:");
        
        for(Student student : list){
            if(student.getName().contains(searchTerm)){
                System.out.println(student);
            }
        }
    }
}
