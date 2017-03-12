
public class Student {
    
    private String name;
    private String studentNumber;
    
    public Student(String name, String studentNumber){
        this.name = name;
        this.studentNumber = studentNumber;
    }
    
    public String getName(){
        return this.name;
    }

    public String getStudentNumber() {
        return studentNumber;
    }
    
    @Override
    public String toString(){
        return this.name + " (" + this.studentNumber + ")";
    }
    
}
