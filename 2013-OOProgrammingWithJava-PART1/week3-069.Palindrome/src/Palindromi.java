import java.util.Scanner;

public class Palindromi {

    public static String reverse(String text) {
        String reversed = "";
        int i = text.length();
       
        while (i > 0) {
            String temp = text.substring(i-1, i);
            reversed += temp;
            i--;
        }
        return reversed;
    }
        
    public static boolean palindrome(String text) {
        String reverse = reverse(text);
        if (text.equals(reverse)){
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        
        System.out.println("Type a text: ");
        String text = reader.nextLine();    
        if (palindrome(text)) {
            System.out.println("The text is a palindrome!");
        } else {
            System.out.println("The text is not a palindrome!");
        }
    }
}
