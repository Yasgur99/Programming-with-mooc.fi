
import java.util.Scanner;
import nhlstats.NHLStatistics;

public class NhlStatisticsPart2 {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);

        System.out.println("NHL statistics service");

        while (true) {
            System.out.println("");
            System.out.print("command (points, goals, assists, penalties, player, club, quit): ");
            String command = reader.nextLine();

            if (command.equals("quit")) {
                break;
            }

            if (command.equals("points")) {
                NHLStatistics.sortByPoints();
                NHLStatistics.top(10);
            } else if (command.equals("goals")) {
                NHLStatistics.sortByGoals();
                NHLStatistics.top(10);
            } else if (command.equals("assists")) {
                NHLStatistics.sortByAssists();
                NHLStatistics.top(10);
            } else if (command.equals("penalties")) {
                NHLStatistics.sortByPenalties();
                NHLStatistics.top(10);
            } else if (command.equals("player")) {
                System.out.println("Which player's statistics do you want?");
                String player = reader.nextLine();
                NHLStatistics.searchByPlayer(player);
            } else if (command.equals("club")) {
                NHLStatistics.sortByPoints();
                System.out.println("Which club's statistics do you want?");
                String club = reader.nextLine();
                NHLStatistics.teamStatistics(club);
            }

        }
    }
}
