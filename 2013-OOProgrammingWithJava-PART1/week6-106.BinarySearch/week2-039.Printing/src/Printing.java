
public class Printing {

    public static void printStars(int amount) {
        while (amount > 0) {
            System.out.print("*");
            amount--;
        }
        System.out.println("");
    }

    public static void printSquare(int sideSize) {
        int i = 0, g = 0;
        while (g < sideSize) {
                printStars(sideSize);
                g++;
        }
    }

    public static void printRectangle(int width, int height) {
        int g =0;
        while(g< height){
            printStars(width);
            g++;
        }
    }

    public static void printTriangle(int size) {
       int i=1;
       while(i < size + 1) {
               printStars(i); 
               i++;
       }
    }

    public static void main(String[] args) {
        printStars(5);
        printStars(3);
        printStars(9);
        System.out.println("\n---");
        printSquare(4);
        System.out.println("\n---");
        printRectangle(5, 6);
        System.out.println("\n---");
        printTriangle(3);
    }
}
