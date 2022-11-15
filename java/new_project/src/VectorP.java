public class VectorP {
    public float x, y, z;
    VectorP(){
        this.x = 0;
        this.y = 0;
        this.z = 0;
    }
    VectorP(float x, float y, float z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
    public void add(VectorP v){
        this.x += v.x;
        this.y += v.y;
        this.z += v.z;
    }
}
