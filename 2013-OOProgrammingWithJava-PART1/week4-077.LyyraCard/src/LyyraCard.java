
public class LyyraCard {

    private double balance;

    public LyyraCard(double userBalance) {
        this.balance = userBalance;
    }
    
    @Override //What is this override thing for!!!!!!!!!!!!!
    public String toString() {
        return "The card has " + this.balance + " Euros";
    }

    public void payEconomical() {
        if (this.balance >= 2.5) {
            this.balance -= 2.50;
        }
    }

    public void payGourmet() {
        if (this.balance >= 4.0) {
            this.balance -= 4.00;
        }
    }

    public void loadMoney(double amount) {
        if(amount < 0){
            
        }else if (this.balance + amount > 150.0) {
            this.balance = 150.0;
        } else {
            this.balance += amount;
        }
    }
}
