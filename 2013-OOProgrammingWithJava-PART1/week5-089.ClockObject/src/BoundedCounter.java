
public class BoundedCounter {

    private int value = 0;
    private int upperLimit;

    public BoundedCounter(int upperLimit) {
        this.upperLimit = upperLimit;
    }

    public void setValue(int num) {
        if (num > this.upperLimit || num < 0) {
            return;
        }
        this.value = num;

    }

    public void next() {
        if (this.value == this.upperLimit) {
            this.value = 0;
        } else if (this.value < this.upperLimit) {
            this.value++;
        }
    }

    public int getValue() {
        return this.value;
    }

    @Override
    public String toString() {
        if (this.value < 10) {
            return "0" + this.value;
        }
        return "" + this.value;
    }
}
