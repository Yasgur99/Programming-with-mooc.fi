
public class Sorting {
    private int[] array;
    
    public Sorting(int[] array){
        this.array = array;
    }  
    
    public static int smallest(int[] array) {
    
    int smallest = array[0];
    for(int i=1; i < array.length; i++){
        if(array[i] < smallest){
            smallest = array[i];
        }
    }
    return smallest;
    }
    
    public static int indexOfTheSmallest(int[] array) {
        int smallest = smallest(array);
        for(int i=0; i < array.length;i++){
            if(array[i] == smallest){
                return i;
            }
        }
        return -1;
    }   
    
    public static int indexOfTheSmallestStartingFrom(int[] array, int index) {
        int[] newArray = new int[array.length - index];
        for(int i=0;i<newArray.length;i++){
            newArray[i] = array[i+index];
        }
        int newIndex = indexOfTheSmallest(newArray);
        return newIndex + index;
    }
    
    public static void swap(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
  
    public static String toString(int[] array){
        String output = "[";
        for(int i=0;i<array.length;i++){
           output += array[i] + ",";
           if(i < array.length - 1){
               output += " ";
           }
        }
        output += "]";
        return output;
    }
    
    public static void sort(int[] array){
        int temp;
        for(int i=0;i<array.length;i++){
            temp= indexOfTheSmallestStartingFrom(array,i);
            swap(array, i, temp);
        }
    }
  
}



