
public class Least {

    public static int least(int number1, int number2) {
        int temp;
        if(number1 < number2){
            temp = number1;
        }else if(number2 < number1) {
            temp = number2;
        }else{
            temp = number1;
        }
        return temp;
    }

    public static void main(String[] args) {
        int result = least(2, 7);
        System.out.println("Least: " + result);
    }
}
