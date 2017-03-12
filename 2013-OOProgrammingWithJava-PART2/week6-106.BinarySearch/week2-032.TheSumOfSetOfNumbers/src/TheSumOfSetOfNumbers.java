
import java.util.Scanner;

public class TheSumOfSetOfNumbers {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int sum = 0;
        int n = 1;
 
        
        System.out.print("Until what? ");
        int until = Integer.parseInt(reader.nextLine());
        
        while(n <= until){
            sum += n;
            n++;
        }
        System.out.println("Sum is " + n);
    }
}
