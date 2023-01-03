public class Vector {
    private double x, y, z;
    public Vector(double x, double y, double z){
        this.set(x, y, z);
    }
    public void set(double x, double y, double z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
    public void sum(Vector v){
        this.x += v.x;
        this.y += v.y;
        this.z += v.z;
    }
    public void cross(Vector v){
        this.x = (this.y * v.z - this.z * v.y);
        this.y = (this.z * v.x - this.x * v.z);
        this.z = (this.x * v.y - this.y * v.x);
    }
    public void unit(){
        double mod = this.module();
        this.x = this.x / mod;
        this.y = this.y / mod;
        this.z = this.z / mod;
    }
    public double module(){
        return Math.sqrt(
            Math.pow(this.x, 2) +
            Math.pow(this.y, 2) + 
            Math.pow(this.z, 2)
        );
    }

}