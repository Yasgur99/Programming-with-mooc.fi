
import java.util.Scanner;

public class SumOfThePowers {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);

        System.out.print("Raise 2 to the what? ");
        int i = Integer.parseInt(reader.nextLine());
        int power = 0;
        int answer = 0;

        while (power <= i) {
            answer += (int) Math.pow(2, power);
            power++;
        }
        System.out.println(answer);
    }
}
