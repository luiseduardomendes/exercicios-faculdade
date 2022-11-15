import java.util.Random;

public class Mine {
    public int x;
    public int y;

    public Mine(int bound_x, int bound_y){
        Random generator = new Random();
        this.x = generator.nextInt(bound_x);
        this.y = generator.nextInt(bound_y);
    }
}
