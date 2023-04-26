public class TextParser {
    private String text;
    private int it = 0;

    public int getIt() {
        return it;
    }
    
    public void setText(String text){
        this.text = text;
    }
    public String getText() {
        return text;
    }

    public String readChar() {
        String input = text.substring(it, it+1);
        if (text.charAt(it) == 'R'){
            if (text.charAt(it+1) == '+' || text.charAt(it+1) == '-'){
                input = text.substring(it, it+2);
            }
            it += 2;
        }
        else if (text.charAt(it) == 'B'){
            if (text.substring(it, it+4).equals("BPM+")){
                input = "BPM+";
            }
            it += 4;
        }
        else{
            it ++;
        }

        return input;
    }
}
