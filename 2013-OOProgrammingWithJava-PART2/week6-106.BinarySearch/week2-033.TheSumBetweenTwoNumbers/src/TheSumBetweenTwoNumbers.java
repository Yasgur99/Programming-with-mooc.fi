
import java.util.Scanner;


public class TheSumBetweenTwoNumbers {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
            int sum = 0;
        
        System.out.print("Start at what? ");
        int start = Integer.parseInt(reader.nextLine());
        
        System.out.print("Until what? ");
        int until = Integer.parseInt(reader.nextLine());
        
        while(start <= until){
            sum += start;
            start++;
        }
        System.out.println("Sum is " + sum);
    }
}
