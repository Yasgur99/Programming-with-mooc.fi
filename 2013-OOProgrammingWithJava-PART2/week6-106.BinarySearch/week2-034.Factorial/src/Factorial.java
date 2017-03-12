import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        
        System.out.print("Type a number: ");
        int a = Integer.parseInt(reader.nextLine());
        int i = 0;
        int product = 1;
        
        while(a > 0){
            if(a == 0){
                product = 1;
                break;
            }
            product *= a;
            a--;
        }
        System.out.println("Factorial is " + product);
    }
}
