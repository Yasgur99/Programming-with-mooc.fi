/*
 * @author michaelmaitland
 */
public class Multiplier {
    
    private int userNumber;
    
    public Multiplier(int number){
        this.userNumber = number;
    }
    
    public int multiply(int otherNumber){
        otherNumber *= this.userNumber;
        return otherNumber;
    }
    
}
