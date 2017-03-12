public class Player {
    private String playerName;
    private int goals;
    
    public Player(String name){
        this.playerName = name;
        this.goals = 0;
    }
    
    public Player (String name, int goals){
        this.playerName = name;
        this.goals = goals;
    }
    
    public String getName(){
        return this.playerName;
    }
    public int goals(){
        return this.goals;
    }
    
    @Override
    public String toString(){
        return this.playerName + ", goals " + this.goals;
    }
}
