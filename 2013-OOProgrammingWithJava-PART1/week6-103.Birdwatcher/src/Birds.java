import java.util.ArrayList;

public class Birds {
    private String name;
    private String latinName;
    private int observations;
   
    public Birds(String name, String latinName){
        this.name = name;
        this.latinName = latinName;
        this.observations = 0;
    }
    
    public void newObservation(){
        this.observations++;
    }
    
    public String getName(){
        return this.name;
    }
    
    public String getLatinName(){
        return this.latinName;
    }
    @Override
    public String toString(){
        return this.name + " (" + this.latinName + "): " + this.observations + " observatoins";
    }
}
