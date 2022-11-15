public class Box {
    private VectorP sup, inf;

    public Box(){
        inf = new VectorP(0,0,0);
        sup = new VectorP(1,1,1);
    }
    public Box(VectorP pos, VectorP size){
        inf = pos;
        size.add(pos);
        sup = size;
    }

    public void moveBox(VectorP motionVector){
        sup.add(motionVector);
        inf.add(motionVector);
    }
}
