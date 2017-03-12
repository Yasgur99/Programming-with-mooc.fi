import java.util.Random;

public class Dice {
    private Random random = new Random();
    private int numberOfSides;
    private int result;

    public Dice(int numberOfSides) {
        this.numberOfSides = numberOfSides + 1;
    }

    public int roll() {
        while(true){
            this.result = random.nextInt(this.numberOfSides);
            if(result > 0){
                break;
            } 
        }
        return result;
    }
}

