public class Entity extends Box{
    public Entity(){
        super();
    }
    public Entity(VectorP pos, VectorP size){
        super(pos, size);
    }

    public void moveN(float instSpd){
        this.moveBox(new VectorP(0.0f,-instSpd, 0.0f));
    }   
    public void moveS(float instSpd){
        this.moveBox(new VectorP(0.0f,+instSpd, 0.0f));
    }   
    public void moveE(float instSpd){
        this.moveBox(new VectorP(instSpd, 0.0f, 0.0f));
    }   
    public void moveW(float instSpd){
        this.moveBox(new VectorP(-instSpd, 0.0f, 0.0f));
    }

    public void moveNW(float instSpd){
        this.moveBox(new VectorP(-instSpd*0.71f, -instSpd/0.71f, 0.0f));
    }   
    public void moveNE(float instSpd){
        this.moveBox(new VectorP(+instSpd/0.71f, -instSpd/0.71f, 0.0f));
    }   
    public void moveSE(float instSpd){
        this.moveBox(new VectorP(+instSpd/0.71f, -instSpd/0.71f, 0.0f));
    }   
    public void moveSW(float instSpd){
        this.moveBox(new VectorP(-instSpd/0.71f, +instSpd/0.71f, 0.0f));
    }
}
