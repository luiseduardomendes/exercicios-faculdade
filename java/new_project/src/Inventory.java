public class Inventory {
    ItemSlot armorSlot, weaponSlot;
    Inventory(){
        this.armorSlot = new ItemSlot(itemTypes.chest);
        this.weaponSlot = new ItemSlot(itemTypes.weapon);
    }
}
