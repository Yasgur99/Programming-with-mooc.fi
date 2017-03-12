
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;


/**
 * @author yasgur99
 *
 */

public class Main {

    public static void main(String[] args) throws Exception{
        Socket s = new Socket("localhost", 8080);
       BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
        System.out.println(br.read());
        
    }
}
