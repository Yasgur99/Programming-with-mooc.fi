public class Counter {
  
    private int counter;
    private boolean checked;
    
    public Counter(int startingValue, boolean check){
        this.counter = startingValue;
        this.checked = check;
    }
    
    public Counter(int startingValue){
        this(startingValue, false);
    }
    
    public Counter(boolean check){
        this(0, check);
    }
    
    public Counter(){
        this(0, false);
    }
    
    public int value(){
        return this.counter;
    }
    
    public void increase(){
        increase(1);
    }
    
    public void increase(int increaseAmount){
        if(increaseAmount >= 0){
            this.counter += increaseAmount;
        }
    }
    
    public void decrease(){
            decrease(1);
        
    }
    
    public void decrease(int decreaseAmount){
        if(decreaseAmount > 0 ){
            if(!this.checked || this.counter > decreaseAmount){
                this.counter -= decreaseAmount;
            } else {
                this.counter = 0;
            }
        }
    }
}
