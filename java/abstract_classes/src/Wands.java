import java.util.ArrayList;
import java.util.Iterator;

public class Wands extends RangedWeapon{
    private ArrayList<String> elements = new ArrayList<String>();
    
    public void addElement(String element){
        elements.add(element);
    }
    @Override
    public String look() {
        String str = new String();
        str = str.concat("You see a ");
        str = str.concat(this.getName());
        str = str.concat("\nMin Level: ");
        str = str.concat(String.valueOf(this.getMinLevel()));
        str = str.concat("\nElements: ");
        Iterator<String> it = this.elements.iterator();
        while(it.hasNext()){
            str = str.concat(it.next());
            str = str.concat(" ");
        }
        str = str.concat("\nDamage: ");
        str = str.concat(String.valueOf(this.getDamage()));
        str = str.concat("\nRange: ");
        str = str.concat(String.valueOf(this.getRange()));
        str = str.concat("\nWeight: ");
        str = str.concat(String.valueOf(this.getWeight()));

        return str;
    }
    @Override
    public void equip() {
        // TODO Auto-generated method stub
        
    }
    
}
