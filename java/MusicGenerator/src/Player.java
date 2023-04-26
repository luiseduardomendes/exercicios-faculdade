import jm.music.data.Part;
import jm.music.data.Phrase;
import jm.music.data.Score;
import jm.util.Play;

public class Player{
    private Synthesizer synth = new Synthesizer();
    private Phrase phrase = new Phrase();
    private Score score = new Score();

    private void addNote(){
        phrase.add(synth.getNote());
    }

    private void changeInstrument(){
        score.add(new Part(phrase, null, synth.getLastInstrument()));
        phrase = new Phrase();
    }

    public void newNote(String str){
        synth.readCharacter(str);
        if (synth.toPlay())
            addNote();
        else if (synth.toChangeInst()){
            changeInstrument();
        }
    }

    public void play(){
        score.add(new Part(phrase, null, synth.getInstrument()));
        Play.midi(score);
    }
}
