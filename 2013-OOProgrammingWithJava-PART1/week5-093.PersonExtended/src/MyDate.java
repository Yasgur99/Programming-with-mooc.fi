
public class MyDate {

    private int day;
    private int month;
    private int year;

    public MyDate(int pv, int kk, int vv) {
        this.day = pv;
        this.month = kk;
        this.year = vv;
    }
    
    public int getDay(){
        return this.day;
    }
    
    public int getMonth(){
        return this.month;
    }
    
    public int getYear(){
        return this.year;
    }

    public String toString() {
        return this.day + "." + this.month + "." + this.year;
    }

    public boolean earlier(MyDate compared) {
        if (this.year < compared.year) {
            return true;
        }

        if (this.year == compared.year && this.month < compared.month) {
            return true;
        }

        if (this.year == compared.year && this.month == compared.month
                && this.day < compared.day) {
            return true;
        }

        return false;
    }

       public int differenceInYears(MyDate comparedDate){
        int totalDays1 = totalDays(this);
        int totalDays2 = totalDays(comparedDate);
        int differenceDays;
        if(totalDays1 < totalDays2){
            differenceDays = totalDays2 - totalDays1;
        } else{
            differenceDays = totalDays1 - totalDays2;
        }
        
        return differenceDays/365;
    }
       
        public int differenceInDays(MyDate comparedDate){
        int totalDays1 = totalDays(this);
        int totalDays2 = totalDays(comparedDate);
        int differenceDays = totalDays2 - totalDays1;
        
        return differenceDays;
    }
    private int totalDays(MyDate date){
        int totalDays = 0;
        
        totalDays += date.day;
        totalDays += date.month*30;
        totalDays += date.year*365;
        
        return totalDays;
    }
}