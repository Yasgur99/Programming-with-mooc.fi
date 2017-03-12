import java.util.Scanner;


public class LastCharacter {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        System.out.print("Type your name:");
        String name = reader.nextLine();
        System.out.println("Last Character: " + lastCharacter(name));
    }
    
    public static char lastCharacter(String name){
        char last = name.charAt(name.length() - 1);
        return last;
    }
}
