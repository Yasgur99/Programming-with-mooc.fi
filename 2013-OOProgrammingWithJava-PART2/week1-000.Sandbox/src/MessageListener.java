import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MessageListener implements ActionListener {

    private String message;
    
    public MessageListener(String message){
        this.message = message;
    }
    @Override
    public void actionPerformed(ActionEvent ae) {
        System.out.println(message);
    }
}