import java.util.ArrayList;
import java.util.Random;

public class LotteryNumbers {
    private ArrayList<Integer> numbers;
    private final Random random = new Random();

    public LotteryNumbers() {
        this.numbers = new ArrayList<Integer>();
        this.drawNumbers();
    }

    public ArrayList<Integer> numbers() {
        return this.numbers;
    }

    public void drawNumbers() {
        this.numbers.clear();
        int number;
        while(this.numbers.size() < 7){
            number = random.nextInt(39) + 1;
            if(!containsNumber(number)){
                this.numbers.add(number);
            }
        }   
    }

    public boolean containsNumber(int number) {
            return this.numbers.contains(number);
    }  
}
