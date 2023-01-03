public abstract class Animal_abstract {
    private Vector pos = new Vector(0, 0, 0);
    
    public abstract void speak();
    public void move(Vector d){
        pos.sum(d);
    }
    public void moveTo(Vector p){
        pos = p;
    }    
}
