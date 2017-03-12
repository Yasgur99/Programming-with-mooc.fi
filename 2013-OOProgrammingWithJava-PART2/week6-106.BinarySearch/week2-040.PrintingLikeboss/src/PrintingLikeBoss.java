
public class PrintingLikeBoss {

    public static void printStars(int amount) {
        while (amount > 0) {
            System.out.print("*");
            amount--;
        }
        System.out.println("");
    }

    public static void printWhitespaces(int amount) {
        while (amount > 0) {
            System.out.print(" ");
            amount--;
        }
    }

    public static void printTriangle(int size) {
        int white = size - 1;
        int stars = 1;
        while (stars <= size) {
            printWhitespaces(white);
            white--;
            printStars(stars);
            stars++;
        }
    }

    public static void xmasTree(int height) {
        int star = 1;
        int lines = height;
        while(lines > 0){
            printWhitespaces(lines-1);
            printStars(star);
            star += 2;
            lines--;
        }
        printWhitespaces(height-2);
        printStars(3);
        printWhitespaces(height-2);
        printStars(3);
    }

    public static void main(String[] args) {

        printTriangle(5);
        System.out.println("---");
        xmasTree(4);
        System.out.println("---");
        xmasTree(10);
    }
}
