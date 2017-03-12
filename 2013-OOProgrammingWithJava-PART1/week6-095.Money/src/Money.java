
public class Money {

    private final int euros;
    private final int cents;

    public Money(int euros, int cents) { //3, -40
        int temp = cents * -1;
        if (cents > 99) {
            euros += cents / 100;
            cents %= 100;
            this.cents = cents;
        }else if(cents < 0){
            euros--;
            temp = 100 - temp;
            while(temp > 100){
                euros--;
                temp = 100 - temp;
            }
            this.cents = temp;
        }else{
            this.cents = cents;
        }
        this.euros = euros;
    }

    public int euros() {
        return euros;
    }

    public int cents() {
        return cents;
    }
    
    public Money plus(Money added){
        Money balance = new Money(this.euros + added.euros, this.cents + added.cents);
        return balance;
    }
    
    public Money minus(Money decremented){
        if(this.less(decremented)){     //Return 0.0e if less than 0
            Money balance = new Money(0,0);
            return balance;
        }else{
            Money balance = new Money(this.euros - decremented.euros, this.cents - decremented.cents);
            return balance;
        }
        
    }

    public boolean less(Money compared){
        if(this.euros < compared.euros){
            return true;
        }else if(this.euros == compared.euros){
            return this.cents < compared.cents;
        }else{
            return false;
        }
    }
    
    @Override
    public String toString() {
        String zero = "";
        if (cents < 10) {
            zero = "0";
        }

        return euros + "." + zero + cents + "e";
    }

}
