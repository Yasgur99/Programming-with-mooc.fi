
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JTextArea;

/**
 * @author yasgur99
 **/

public class AreaCopier implements ActionListener {

    private JTextArea origin;
    private JTextArea destination;
    
    public AreaCopier(JTextArea origin, JTextArea destination){
        this.origin = origin;
        this.destination = destination;
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        this.destination.setText(this.origin.getText());
     }

    
}
