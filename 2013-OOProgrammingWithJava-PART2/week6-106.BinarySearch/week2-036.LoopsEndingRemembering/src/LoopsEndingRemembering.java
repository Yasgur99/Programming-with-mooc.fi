
import java.util.Scanner;

public class LoopsEndingRemembering {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int response = 0;
        int sum = 0;
        int i = 0;

        int even = 0, odd = 0;

        System.out.println("Type numbers:");

        while (response != -1) {
            response = Integer.parseInt(reader.nextLine());
            if (response != -1) {
                sum += response;
                i++;

                if (response % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
        }
        System.out.println("Thank you and see you later!");
        System.out.println("The sum is " + sum);
        System.out.println("How many numbers: " + i);
        System.out.println("Average: " + ((double) sum / i));

        System.out.println("Even numbers: " + even);
        System.out.println("Odd numbers: " + odd);
    }
}
