
public class StringUtils {
    
    public static boolean included(String word, String searched){
        if(word.isEmpty() || searched.isEmpty()){
            return false;
        }
        word = word.toUpperCase();
        searched = searched.toUpperCase();
        
        word = word.trim();
        searched = searched.trim();
         
        if(word.contains(searched)){
            return true;
        }else{
            return false;
        }
    }
}
