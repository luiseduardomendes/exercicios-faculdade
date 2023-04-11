public class App {
    public static void main(String[] args) throws Exception {
        Wands wand;

        wand = new Wands();
        wand.setMinLevel(0);
        wand.setName("Wand of Decay");
        wand.setWeight(13.5);
        wand.setDamage(15);
        wand.setRange(15);
        wand.addEffects("Decomposition");
        wand.addElement("Death");
        
        EquipableItems slot1 = wand;

        System.out.println(slot1.look());
    }
}
