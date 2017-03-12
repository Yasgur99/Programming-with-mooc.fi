
public class HangmanLogic {

    private String word;
    private String guessedLetters;
    private int numberOfFaults;

    public HangmanLogic(String word) {
        this.word = word.toUpperCase();
        this.guessedLetters = "";
        this.numberOfFaults = 0;
    }

    public int numberOfFaults() {
        return this.numberOfFaults;
    }

    public String guessedLetters() {
        return this.guessedLetters;
    }

    public int losingFaultAmount() {
        return 12;
    }

    public void guessLetter(String letter) {
        if (!this.word.contains(letter) && !this.guessedLetters.contains(letter)) {
            this.numberOfFaults++;
        }
        if (!this.guessedLetters.contains(letter)) {
            this.guessedLetters += letter;
        }
    }

    public String hiddenWord() {
        int i = 0;
        char letter;
        String aLetter;
        String hiddenWord = "";

        while (i < this.word.length()) { // Create hidden word
            hiddenWord += "_";
            i++;
        }

        for (i = 0; i < this.word.length(); i++) {
            letter = this.word.charAt(i);
            aLetter = "" + letter;
            if (this.guessedLetters.contains(aLetter)) {
                hiddenWord = hiddenWord.substring(0, i) + aLetter + hiddenWord.substring(i + 1);
            }
        }
        return hiddenWord;
    }
}
