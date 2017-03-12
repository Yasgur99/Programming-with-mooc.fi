
import java.util.Scanner;

public class LengthOfName {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        System.out.print("Type your name: ");
        String name = reader.nextLine();
        System.out.println("Number of Characters: " + calculateCharacters(name));
    }

    public static int calculateCharacters(String text){
      int length = text.length();
      return length;  
    }
}
