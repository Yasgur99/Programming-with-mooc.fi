
import java.util.Scanner;

public class SumOfTheAges {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);

        // Implement your program here
        System.out.print("Type your name: ");
        String name1 = reader.nextLine();
        System.out.print("Type your age: ");
        int a = Integer.parseInt(reader.nextLine());
        
        System.out.print("Type your name: ");
        String name2 = reader.nextLine();
        System.out.print("Type your name: ");
        int b = Integer.parseInt(reader.nextLine());
        
        System.out.println(name1 + " and " + name2 + " are " + (a + b) + " years old in total.");
                
    }
}
