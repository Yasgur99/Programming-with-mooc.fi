import java.util.ArrayList;

public class Variance {
    
    public static int sum(ArrayList<Integer> list) {
        int sum = 0;
        for(int entry : list){
            sum += entry;
        }
        return sum;
    }
    
    public static double secondSum(ArrayList<Double> list) {
        double sum = 0;
        for(double entry : list){
            sum += entry;
        }
        return sum;
    }
 
    public static double average(ArrayList<Integer> list) {
        double sum = sum(list);
        double average = sum / list.size();
        return average;
    }
    
    public static double secondAverage(ArrayList<Double> list) {
        double sum = secondSum(list);
        double average = sum / (list.size() - 1);
        return average;
    }
    

    public static double variance(ArrayList<Integer> list) {
        ArrayList<Double> differenceSquared = new ArrayList<Double>();
        double firstAverage = average(list);
        for(int entry : list){
             differenceSquared.add((entry - firstAverage)*(entry - firstAverage));
        }
        double variance = secondAverage(differenceSquared);
       
        
      
        return variance;
    }
    
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(3);
        list.add(2);
        list.add(7);
        list.add(2);
 
        System.out.println("The variance is: " + variance(list));
    }

}
