public class Item {
    public Boolean equipable;
    public itemTypes itemType;
    public itemID itemID;

    Item(Boolean equipable, itemTypes itemType, itemID itemID){
        this.equipable = equipable;
        this.itemType = itemType;
        this.itemID = itemID;
    }

    public itemTypes getItemType() {
        return itemType;
    }

    public itemID getItemID(){
        return this.itemID;
    }
    
}
