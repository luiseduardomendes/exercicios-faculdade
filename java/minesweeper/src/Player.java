public class Player {
    private Boolean[][] __open__;
    private Boolean[][] __flag__;

    private int width;
    private int height;

    public Player(int w, int h){
        this.__open__ = new Boolean[h][w];
        this.__flag__ = new Boolean[h][w];

        this.width = w;
        this.height = h;

        this.__initArray__();
    }

    private void __initArray__(){
        for (int y = 0; y < this.height; y ++){
            for (int x = 0; x < this.width; x ++){
                this.__open__[y][x] = false;
            }
        }
        for (int y = 0; y < this.height; y ++){
            for (int x = 0; x < this.width; x ++){
                this.__flag__[y][x] = false;
            }
        }
    }

    public Boolean is_open(int x, int y){
        return this.__open__[y][x];
    }

    public Boolean is_flag(int x, int y){
        return this.__flag__[y][x];
    }

    public void change_flag(int x, int y){
        this.__flag__[y][x] = !this.__flag__[y][x];
    }

    public void open(int x, int y){
        this.__open__[y][x] = true;
    }
    
}
