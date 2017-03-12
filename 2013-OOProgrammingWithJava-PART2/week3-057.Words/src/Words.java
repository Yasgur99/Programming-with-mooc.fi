import java.util.ArrayList;
import java.util.Scanner;

public class Words {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        ArrayList<String> words = new ArrayList<String>();
        int i = 0;
        
        do{
        System.out.println("Type a word: ");
        words.add(reader.nextLine());
        i++;
        } while(!words.get(i-1).equals(""));
        
        System.out.println("You typed the following words:");
        
        for(String entry : words){
            System.out.println(entry);
        }
        
    }
}
