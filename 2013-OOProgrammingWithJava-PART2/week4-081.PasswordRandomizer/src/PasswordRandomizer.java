import java.util.Random;

public class PasswordRandomizer {
    private Random random = new Random();
    private int length;
    
    public PasswordRandomizer(int length) {
        this.length = length;
    }

    public String createPassword() {
        
        String password = ""; 
        String charSet = "abcdefghijklmnopqurstuvwxyz";
        
        for(int i = this.length; i > 0; i--){
            password += charSet.charAt(random.nextInt(25));
        }
        return password;
    }
}
