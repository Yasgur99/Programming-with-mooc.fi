import java.util.Scanner;

public class FirstCharacter {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        
        System.out.print("Type your name: ");
        String name = reader.nextLine();
        System.out.println("First character: " + firstCharacter(name));
    }
    
    public static char firstCharacter(String name){
       char char1 = name.charAt(0);
       return char1;
    }
}
