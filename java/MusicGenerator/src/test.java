import jm.JMC;
import jm.music.data.Note;
import jm.music.data.Phrase;
public class test {
    private Note[] bella_ciao_notes = {
        new Note(JMC.a4, JMC.C, 0),
        new Note(JMC.B3, JMC.SEMI_QUAVER),
        new Note(JMC.E4, JMC.SEMI_QUAVER),
        new Note(JMC.F4, JMC.SEMI_QUAVER),
        new Note(JMC.G4, JMC.SEMI_QUAVER),
        new Note(JMC.E4, JMC.C),

        new Note(JMC.B3, JMC.SEMI_QUAVER),
        new Note(JMC.E4, JMC.SEMI_QUAVER),
        new Note(JMC.F4, JMC.SEMI_QUAVER),
        new Note(JMC.G4, JMC.SEMI_QUAVER),
        new Note(JMC.E4, JMC.C),

        new Note(JMC.B3, JMC.SEMI_QUAVER),
        new Note(JMC.E4, JMC.SEMI_QUAVER),
        new Note(JMC.F4, JMC.SEMI_QUAVER),
        new Note(JMC.G4, JMC.QUAVER),

        new Note(JMC.F4, JMC.SEMI_QUAVER),
        new Note(JMC.E4, JMC.SEMI_QUAVER),
        new Note(JMC.G4, JMC.QUAVER),

        new Note(JMC.F4, JMC.SEMI_QUAVER),
        new Note(JMC.E4, JMC.SEMI_QUAVER),
        new Note(JMC.B4, JMC.QUAVER),
        new Note(JMC.B4, JMC.QUAVER),
        new Note(JMC.B4, JMC.SEMI_QUAVER),
        new Note(JMC.B4, JMC.SEMI_QUAVER),
        new Note(JMC.A4, JMC.SEMI_QUAVER),
        new Note(JMC.B4, JMC.SEMI_QUAVER),

        new Note(JMC.C5, JMC.SEMI_QUAVER),
        new Note(JMC.C5, JMC.C),

        new Note(JMC.C5, JMC.SEMI_QUAVER),
        new Note(JMC.B4, JMC.SEMI_QUAVER),
        new Note(JMC.A4, JMC.SEMI_QUAVER),

        new Note(JMC.E5, JMC.SEMI_QUAVER),
        new Note(JMC.B4, JMC.C),

        new Note(JMC.B4, JMC.SEMI_QUAVER),
        new Note(JMC.A4, JMC.SEMI_QUAVER),
        new Note(JMC.G4, JMC.SEMI_QUAVER),
        
        new Note(JMC.F4, JMC.QUAVER),
        new Note(JMC.B4, JMC.QUAVER),
        new Note(JMC.G4, JMC.QUAVER),
        new Note(JMC.F4, JMC.QUAVER),

        new Note(JMC.D4, JMC.C),
    };
    Phrase bella_ciao_phrase = new Phrase(bella_ciao_notes);
}
