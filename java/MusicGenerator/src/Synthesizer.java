import jm.JMC;
import jm.music.data.Note;

public class Synthesizer {
    private SystemStatus status = new SystemStatus();
    private char lastChar = '\0';
    private int lastInstrument;
    private boolean playNextNote;
    private boolean changeInstrument;

    public Note getNote(){
        return status.get();
    }
    public int getInstrument(){
        return status.getInstrument();
    }
    public int getLastInstrument() {
        return lastInstrument;
    }

    public void readCharacter(String str){
        playNextNote = false;
        changeInstrument = false;
        if (str.equals("A") || str.equals("a")){
            status.setNote('A');
            playNextNote = true;
        }
        else if (str.equals("B") || str.equals("b")){
            status.setNote('B');
            playNextNote = true;
        }
        else if (str.equals("C") || str.equals("c")){
            status.setNote('C');
            playNextNote = true;
        }
        else if (str.equals("D") || str.equals("d")){
            status.setNote('D');
            playNextNote = true;
        }
        else if (str.equals("E") || str.equals("e")){
            status.setNote('E');
            playNextNote = true;
        }
        else if (str.equals("F") || str.equals("f")){
            status.setNote('F');
            playNextNote = true;
        }
        else if (str.equals("G") || str.equals("g")){
            status.setNote('G');
            playNextNote = true;
        }
        else if (str.equals("+")){
            status.duplicateVolume();
        }
        else if (str.equals("-")){
            status.resetVolume();
        }
        else if (
            str.equals("O") | 
            str.equals("I") | 
            str.equals("U") | 
            str.equals("o") | 
            str.equals("i") | 
            str.equals("u")
        ){
            if (!((lastChar >= 'A' && lastChar <= 'G') || 
            (lastChar >= 'a' && lastChar <= 'g'))){
                status.setNote(JMC.B2);
            }
            playNextNote = true;
        }
        else if (str.equals("R+")){
            status.incOctave();
        }
        else if (str.equals("R-")){
            status.decOctave();
        }
        else if (str.equals("?")){
            status.randomNote();
            playNextNote = true;
        }
        else if (str.equals("\n")){
            lastInstrument = status.getInstrument();
            status.randomInstrument();
            changeInstrument = true;
        }
        else if (str.endsWith("BPM+")){
            status.incBpm(80);
        }
        else if (str.equals(";")){
            status.randomBpm();
        }
    }

    public boolean toPlay(){
        return playNextNote;
    }

    public boolean toChangeInst(){
        return changeInstrument;
    }
}



