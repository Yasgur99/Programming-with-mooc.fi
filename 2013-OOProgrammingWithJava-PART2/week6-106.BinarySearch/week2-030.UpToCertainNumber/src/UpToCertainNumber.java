
import java.util.Scanner;


public class UpToCertainNumber {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int i = 1;
        
        System.out.print("What number would you like to go up to? ");
        int request = Integer.parseInt(reader.nextLine());
        
        while(i <= request) {
            System.out.println(i);
            i++;
        }   
    }
}
