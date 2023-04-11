import java.util.Random;
import jm.music.data.Note;
import jm.JMC;

public class SystemStatus {
    private final int standardVolume = JMC.P;
    
    private int volume;
    private int note;
    private int octave;
    private int instrument;
    private int bpm;

    SystemStatus(){
        note = JMC.A4;
        octave = 4;
        instrument = JMC.PIANO;
        bpm = 60;
        volume = JMC.P;
    }

    public Note get(){
        return new Note(note, 60.0/bpm, volume);
    }

    public void setVolume(int volume){
        this.volume = volume;
    }
    public int getVolume() {
        return volume;
    }
    public void setNote(int note){
        this.note = note;
    }
    public void setNote(char note) {
        int k = 0;
        switch (note){
            case 'C' : 
                k = 0;
                break;
            case 'D' :
                k = 2; 
                break;
            case 'E' : 
                k = 4;
                break;
            case 'F' : 
                k = 5;
                break;
            case 'G' : 
                k = 7;
                break;
            case 'A' :
                k = 9; 
                break;
            case 'B' : 
                k = 11;
                break;
        }
        this.note = 12 * octave + k;
    }
    public int getNote() {
        return note;
    }
    public void setOctave(int octave) {
        this.octave = octave;
    }
    public int getOctave() {
        return octave;
    }
    public void setInstrument(int instrument) {
        this.instrument = instrument;
    }
    public int getInstrument() {
        return instrument;
    }
    public void setBpm(int bpm) {
        this.bpm = bpm;
    }
    public int getBpm() {
        return bpm;
    }

    public void duplicateVolume(){
        volume = 2*volume;
    }
    public void resetVolume(){
        volume = standardVolume;
    }

    public void decOctave(){
        if (octave >= 1){
            octave -= 1;
            note -= 12;   
        }
    }
    public void incOctave(){
        octave += 1;
        note += 12;
    }
    public void randomNote(){
        Random random = new Random();
        int[] notes = {0,2,4,5,7,9,11};
        note = notes[random.nextInt(0, 7)] + 12 * octave;
    }
    public void incBpm(int inc){
        bpm = bpm + inc;
    }
    public void randomBpm(){
        Random random = new Random();
        bpm = random.nextInt(0, 250);
    }
    public void randomInstrument(){
        Random random = new Random();
        instrument = random.nextInt(0, 127);
    }
}
