
import java.util.Scanner;

public class LowerLimitAndUpperLimit {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        
        System.out.print("Enter number to start at: ");
        int start = Integer.parseInt(reader.nextLine());
        
        System.out.print("Enter number to end at: ");
        int end = Integer.parseInt(reader.nextLine());
        
        if(start > end){
            System.out.println("Error: Start value must be less than end value.");
        }
        
        while(start <= end){
            System.out.println(start);
            start++;
        }
    }
}
