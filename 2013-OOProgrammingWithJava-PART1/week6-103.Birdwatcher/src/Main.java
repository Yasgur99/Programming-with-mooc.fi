import java.util.Scanner;

public class Main {  

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BirdDatabase database = new BirdDatabase();
        System.out.print("? ");
        String command = sc.nextLine();
        
        while(!command.equals("Quit")){
            command = command.toLowerCase();
            command = command.trim();
            
           if(command.equals("add")){
               System.out.print("Name: ");
               String name = sc.nextLine();
               System.out.print("Latin Name: ");
               String latinName = sc.nextLine();
              database.addBird(new Birds(name, latinName));
           } else if(command.equals("observation")){
               System.out.print("What was observed:? ");
               String observed = sc.nextLine();
               database.observation(observed);
           } else if(command.equals("statistics")){
               database.statistics();
           } else if(command.equals("show")){
               System.out.print("What? ");
               String bird = sc.nextLine();
               database.show(bird);
           } else {
               System.out.println("Sorry, please enter a valid command.");
           }
           System.out.print("? ");
           command = sc.nextLine();
        }
    }

}
