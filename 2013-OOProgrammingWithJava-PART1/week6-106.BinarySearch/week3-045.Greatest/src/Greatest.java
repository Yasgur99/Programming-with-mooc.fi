
public class Greatest {

    public static int greatest(int number1, int number2, int number3) {
        int temp;
        if(number1 > number2 && number1 > number3){
        temp = number1;
        }else if(number2 > number1 && number2 > number3){
        temp = number2;
        }else{
        temp = number3;
        }
        
        return temp;
    }

    public static void main(String[] args) {
        int result = greatest(2, 7, 3);
        System.out.println("Greatest: " + result);
    }
}