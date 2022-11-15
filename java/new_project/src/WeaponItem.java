public class WeaponItem extends Item{
    private float damage;

    public WeaponItem(float damage){
        super(true);
    }

    public float getDamage(){
        return damage;
    }
}
