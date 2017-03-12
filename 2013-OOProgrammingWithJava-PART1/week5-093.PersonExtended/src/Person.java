import java.util.Calendar;

public class Person {
    private String name;
    private MyDate birthday;
    
    public Person(String name, int pp, int kk, int vv) {
        this.name = name;
        this.birthday = new MyDate(pp, kk, vv);
    }
    
    public Person(String name, MyDate birthday){
        this(name, birthday.getDay(), birthday.getMonth(), birthday.getYear());
    }
    
    public Person(String name){
        this(name,Calendar.getInstance().get(Calendar.DATE),Calendar.getInstance().get(Calendar.MONTH) + 1, 
        Calendar.getInstance().get(Calendar.YEAR));
    }
    
    
    public int age() {
        MyDate today = new MyDate(Calendar.getInstance().get(Calendar.DATE),Calendar.getInstance().get(Calendar.MONTH) + 1, 
        Calendar.getInstance().get(Calendar.YEAR));
        
        return birthday.differenceInYears(today);
    }
    
    
    public String getName() {
        return this.name;
    }
    
    boolean olderThan(Person compared){
    if(this.birthday.differenceInDays(compared.birthday) > 0){
        return true;
    }
    return false;
    }
    
    public String toString() {
        return this.name + ", born " + this.birthday;
    }
}
