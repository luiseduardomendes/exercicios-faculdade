public class Triangle {
    private double a, b, c;

    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public void setEdgesLength(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public boolean isTriangle() {
        if (a <= 0 || b <= 0 || c <= 0){
            return false;
        }
        else if (a + b > c && a + c > b && b + c > a){
            return true;
        }
        else{
            return false;
        }
    }

    public String classification(){
        if (isTriangle()){
            if (a == b && a == c){
                return "Equilateral";
            } else if (a == b || a == c || b == c){
                return "Isosceles";
            } else{
                return "Scalene";
            }
        }
        else{
            return "NotTriangle";
        }
    }
}
