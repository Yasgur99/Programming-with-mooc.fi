
import java.util.Scanner;

public class EvenOrOdd {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);

        System.out.print("Type a number: ");
        int a = Integer.parseInt(reader.nextLine());
        
        boolean isOdd = (a % 2) != 0;
        
        if(isOdd){
            System.out.println("Number " + a + " is odd.");
        }else {
            System.out.println("Number " + a + " is even.");
        }
    }
}
