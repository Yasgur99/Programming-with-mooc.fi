
import java.util.Scanner;

public class GradesAndPoints {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);

        System.out.print("Type the points [0-60]: ");
        int grade = Integer.parseInt(reader.nextLine());
        
        if(grade >= 0 && grade <= 29){
            System.out.println("failed");
        } else if (grade > 29 && grade <= 34){
            System.out.println("Grade: 1");
        }else if (grade > 34 && grade <= 39){
            System.out.println("Grade: 2");
        }else if (grade > 39 && grade <= 44){
            System.out.println("Grade: 3");
        }else if (grade > 44 && grade <= 49){
            System.out.println("Grade: 4");
        }else if (grade > 49 && grade <= 60){
            System.out.println("Grade: 5");
        }
    }
}
