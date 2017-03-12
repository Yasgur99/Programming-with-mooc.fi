public class Reformatory {
    
    private int timesWeightMeasured;

    public int weight(Person person) {
        this.timesWeightMeasured += 1;
        return person.getWeight();
    }
    
    public void feed(Person person){
        person.setWeight(1 + weight(person));
    }
    
    public int totalWeightsMeasured(){
        return this.timesWeightMeasured;
    }

}
