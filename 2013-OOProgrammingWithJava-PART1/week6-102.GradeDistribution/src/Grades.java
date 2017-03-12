
import java.util.Scanner;
import java.util.ArrayList;

public class Grades {

    private Scanner sc;
    private ArrayList<Integer> grades;
    private int fails;

    public Grades(Scanner sc) {
        this.sc = sc;
        this.grades = new ArrayList<Integer>();
        this.fails = 0;
    }

    public void inputGrades() {
        System.out.println("Type exam scores, -1 completes:");
        int temp = sc.nextInt();
        while (temp != -1) {

            this.grades.add(temp);
            temp = sc.nextInt();
        }
    }

    public void gradeDistribution() {
        int lower = 49;
        int higher = 60;
        int temp;

        System.out.println("Grade Distribution:");

        for (int i = 5; i > -1; i--) {
            System.out.print(i + ": ");
            
            for (int grade : this.grades) {
  
                if (grade <= higher && grade > lower) {
                    System.out.print("*");
                }
                
            }

            if (i == 1) {
                lower = -1;
                higher = 29;
                
            } else {
                temp = lower;
                higher = temp;
                lower -= 5;
            }

            System.out.println("");
        }
    }

    public String acceptance() {
        for(int grade : grades){
            if(grade > 60 || (grade  <= 29 && grade >= 0)){
                    this.fails++;
            }
        }
        
        String percentage = "Acceptance Percentage: " + (100.0 * (this.grades.size() - this.fails) / this.grades.size());
        return percentage;
    }
}
