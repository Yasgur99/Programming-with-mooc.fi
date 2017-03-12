
import nhlstats.NHLStatistics;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.println("Top ten by points");
        
        NHLStatistics.sortByGoals();
        NHLStatistics.top(10);
        
        NHLStatistics.sortByPenalties();
        NHLStatistics.top(25);
        
        NHLStatistics.searchByPlayer("Sidney Crosby");
        NHLStatistics.teamStatistics("PHI");
        
        NHLStatistics.sortByPoints();
        NHLStatistics.teamStatistics("ANA");
        
        
        
        
        
    }
}
