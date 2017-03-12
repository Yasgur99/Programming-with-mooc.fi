import java.util.Scanner;

public class GuessingGame {

    private Scanner reader;

    public GuessingGame() {
        this.reader = new Scanner(System.in);
    }

    public void play(int lowerLimit, int upperLimit) {
        instructions(lowerLimit, upperLimit);
        int maxQuestions = howManyTimesHalvable(upperLimit - lowerLimit);
        
        while(lowerLimit != upperLimit){
            if(isGreaterThan(average(upperLimit,lowerLimit))){
                lowerLimit = average(upperLimit, lowerLimit) + 1;
            } else{
                upperLimit = average(upperLimit, lowerLimit);
            }
        }
        System.out.println("The number you are thinking of is " + upperLimit);
            }

    

    public void instructions(int lowerLimit, int upperLimit) {
        int maxQuestions = howManyTimesHalvable(upperLimit - lowerLimit);

        System.out.println("Think of a number between " + lowerLimit + "..." + upperLimit + ".");

        System.out.println("I promise you that I can guess the number you are thinking with " + maxQuestions + " questions.");
        System.out.println("");
        System.out.println("Next I'll present you a series of questions. Answer them honestly.");
        System.out.println("");
    }

    // a helper method:
    public static int howManyTimesHalvable(int number) {
        // we create a base two logarithm  of the given value

        // Below we swap the base number to base two logarithms!
        return (int) (Math.log(number) / Math.log(2)) + 1;
    }
    
    public boolean isGreaterThan(int num){
        System.out.println("Is your number greater than " + num + "? (y/n)");
        String response = this.reader.nextLine();
        response.toLowerCase();
        if(response.equals("y")){
            return true;
        }else
            return false;
        }
    
    public int average(int upperLimit, int lowerLimit){
        return (upperLimit + lowerLimit) / 2;
    }
}

