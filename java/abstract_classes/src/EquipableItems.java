public abstract class EquipableItems {
    private String name;
    private double weight;
    private int minLevel = 0;

    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
    
    public void setMinLevel(int minLevel) {
        this.minLevel = minLevel;
    }
    public int getMinLevel() {
        return minLevel;
    }
    public boolean isEquipable(int level){
        return level > this.minLevel;
    }

    public void setWeight(double weight){
        this.weight = weight;
    }
    public double getWeight(){
        return this.weight;
    }

    public abstract String look();
    public abstract void equip();

}
