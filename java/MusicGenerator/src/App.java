import jm.music.data.Note;
import jm.music.data.Phrase;
import jm.music.data.Part;
import jm.music.data.Score;
import jm.util.Play;

import jm.JMC;

public class App {
    public static void main(String[] args) throws Exception {
        int[] scale1 = {JMC.D3,  JMC.D3};
        int[] scale2 = {JMC.A3,  JMC.A3};
        int[] scale3 = {JMC.D4,  JMC.D4};
        int[] scale4 = {JMC.FS4, JMC.F4};

        Note[] notes1 = new Note[scale1.length];
        Note[] notes2 = new Note[scale1.length];
        Note[] notes3 = new Note[scale1.length];
        Note[] notes4 = new Note[scale1.length];

        
        for (int i = 0; i < scale1.length; i ++){
            notes1[i] = new Note(scale1[i], JMC.C, JMC.MF);
            notes2[i] = new Note(scale2[i], JMC.C, JMC.MF);
            notes2[i].setOffset(0.004);
            notes3[i] = new Note(scale3[i], JMC.C, JMC.MF);
            notes3[i].setOffset(0.008);
            notes4[i] = new Note(scale4[i], JMC.C, JMC.MF);
            notes4[i].setOffset(0.012);
        }
        
        Phrase[] phrases = {
            new Phrase(notes1), 
            new Phrase(notes2), 
            new Phrase(notes3), 
            new Phrase(notes4)
        };
        
        int instrument = JMC.AC_GUITAR;
        Score score = new Score();
        score.addPart(new Part(phrases[0], "guitar1", instrument));
        score.addPart(new Part(phrases[1], "guitar2", instrument));
        score.addPart(new Part(phrases[2], "guitar3", instrument));
        score.addPart(new Part(phrases[3], "guitar4", instrument));

        Play.midi(score);
    }
}
