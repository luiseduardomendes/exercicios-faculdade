public class ItemSlot {
    private itemTypes typeSlot;
    private Item itemStored;
    
    ItemSlot(itemTypes typeSlot){
        this.typeSlot = typeSlot;
    }

    public Item storeItem(Item item){
        Item buffer = itemStored;
        if (typeSlot.compareTo(item.getItemType()) == 0){
            this.itemStored = item;
        }
        return buffer;
    }

    public Item getStoredItem(){
        return itemStored;
    }
}
