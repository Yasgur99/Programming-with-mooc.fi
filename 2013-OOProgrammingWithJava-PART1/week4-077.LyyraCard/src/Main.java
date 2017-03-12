
public class Main {
    public static void main(String[] args) {
        LyyraCard cardPekka = new LyyraCard(20);
        LyyraCard cardBrian = new LyyraCard(30);
        
        cardPekka.payGourmet();
        cardBrian.payEconomical();
       
        cardBalances(cardPekka, cardBrian);
        
        cardPekka.loadMoney(20.0);
        
        cardBrian.payGourmet();
        
        cardBalances(cardPekka, cardBrian);
        
        cardPekka.payEconomical();
        cardPekka.payEconomical();
        
        cardBrian.loadMoney(50);
        
        cardBalances(cardPekka, cardBrian);
    }
    
    public static void cardBalances(LyyraCard cardPekka, LyyraCard cardBrian ){
        System.out.println("Pekka: " + cardPekka);
        System.out.println("Brian: " + cardBrian);
    }
}