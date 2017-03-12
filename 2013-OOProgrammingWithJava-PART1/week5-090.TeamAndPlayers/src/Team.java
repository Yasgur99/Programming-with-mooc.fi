
import java.util.ArrayList;
public class Team {
    private String teamName;
    private ArrayList<Player> players = new ArrayList<Player>();
    private int maxSize;
    
    
    public Team(String teamName){
        this.teamName = teamName;
        this.maxSize = 16;
    }
    
    public String getName(){
        return this.teamName;
    }
    
    public void addPlayer(Player player){
        if(players.size() < this.maxSize){
            this.players.add(player);
        }
    }
    
    public void printPlayers(){
        for (Player player : this.players){
            System.out.println(player);
        }
    }
    
    public void setMaxSize(int maxSize){
        this.maxSize = maxSize;
    }
    
    public int size(){
        return players.size();
    }
    
    public int goals(){
        int totalGoals = 0;
        for(Player player : players){
            totalGoals += player.goals();
        }
        return totalGoals;
    }
}
