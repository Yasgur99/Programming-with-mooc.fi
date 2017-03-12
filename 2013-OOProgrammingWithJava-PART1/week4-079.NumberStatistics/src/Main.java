import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        NumberStatistics stats = new NumberStatistics();
        NumberStatistics even = new NumberStatistics();
        NumberStatistics odd = new NumberStatistics();
        Scanner reader = new Scanner(System.in);
        
        System.out.println("Type numbers(-1 to finish)");
        int number = Integer.parseInt(reader.nextLine());
        
        while (number != -1){
            if(number % 2 ==0){
                even.addNumber(number);
            }else {
                odd.addNumber(number);
            }
            
            stats.addNumber(number);
            number = Integer.parseInt(reader.nextLine());
        }
        System.out.println("Sum: " +stats.sum());
        System.out.println("Sum of even: " + even.sum());
        System.out.println("Sum of odd: " + odd.sum());
    }
}
