import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        Grades grades = new Grades(sc);
        grades.inputGrades();
        grades.gradeDistribution();
        System.out.println(grades.acceptance());
    }
}
