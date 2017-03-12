public class MyDate {
    private int day;
    private int month;
    private int year;

    public MyDate(int day, int montd, int year) {
        this.day = day;
        this.month = montd;
        this.year = year;
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

    private int totalDays(MyDate date){
        int totalDays = 0;
        
        totalDays += date.day;
        totalDays += date.month*30;
        totalDays += date.year*365;
        
        return totalDays;
    }
}
