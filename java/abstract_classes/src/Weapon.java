import java.util.ArrayList;

public abstract class Weapon extends EquipableItems{
    private double damage;
    private ArrayList<String> effects = new ArrayList<String>();
    
    public ArrayList<String> getEffects() {
        return effects;
    }
    public void addEffects(String effect){
        this.effects.add(effect);
    }

    public void setDamage(double damage){
        this.damage = damage;
    }
    public double getDamage(){
        return this.damage;
    }
}
