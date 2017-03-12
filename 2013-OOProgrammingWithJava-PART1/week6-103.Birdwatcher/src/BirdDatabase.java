import java.util.ArrayList;

public class BirdDatabase {
    private ArrayList<Birds> database;
    
    public BirdDatabase(){
        this.database = new ArrayList<Birds>();
    }
    
    public void addBird(Birds bird){
        this.database.add(bird);
    }
    
    public void observation(String observation){
        for(Birds bird : this.database){
            if(bird.getName().equals(observation) || bird.getLatinName().equals(observation)){
                bird.newObservation();
                return;
            } 
            System.out.println("It's not a bird!");
            }
        }
    
    public void statistics(){
        for(Birds bird : this.database){
            System.out.println(bird);
        }
    }
        
    public void show(String birdName){
        for(Birds bird : this.database){
            if(birdName.equals(bird.getName()) || birdName.equals(bird.getLatinName())){
                System.out.println(bird);
            }else{
                System.out.println("Not a bird!");
            }
        }
    }

    }
    

