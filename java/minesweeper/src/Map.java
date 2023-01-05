public class Map {
    public int width;
    public int height;

    public int num_mines;
    
    private int[][] __map__;

    public Map(int w, int h, double perc_mines){
        this.width = w;
        this.height = h;
        this.num_mines = (int)(w * h * perc_mines);
        
        this.init();
    }

    private void init(){
        this.__map__ = new int[this.height][this.width];
        
        this.__initArray__();
        this.__initMap__();
    }

    private void __initArray__(){
        for (int y = 0; y < this.height; y ++){
            for (int x = 0; x < this.width; x ++){
                this.__map__[y][x] = 0;
            }
        }
    }

    private void __initMap__(){
        this.__map__ = new int[this.height][this.width];
        Mine tempMine = new Mine(this.width, this.height);
        int count;

        for (int y = 0; y < this.height; y ++){
            for (int x = 0; x < this.width; x ++){
                this.__map__[y][x] = 0;
            }
        }
        for (int i = 0; i < this.num_mines; i ++){
            do {
                tempMine = new Mine(this.width, this.height);
            } while (this.__map__[tempMine.y][tempMine.x] != 0);
            this.__map__[tempMine.y][tempMine.x] = -1;
        }
        for (int y = 0; y < this.height; y ++){
            for (int x = 0; x < this.width; x ++){
                if (this.__map__[y][x] == -1){
                    continue;
                }
                count = 0;
                if (y > 0){
                    if (this.__map__[y-1][x] == -1){
                        count ++;
                    }
                    if (x > 0){
                        if (this.__map__[y-1][x-1] == -1){
                            count ++;
                        }
                    }
                    if (x < this.width - 1){
                        if (this.__map__[y-1][x+1] == -1){
                            count ++;
                        }
                    } 
                }
                if (y < this.height - 1){
                    if (this.__map__[y+1][x] == -1){
                        count ++;
                    }
                    if (x > 0){
                        if (this.__map__[y+1][x-1] == -1){
                            count ++;
                        }
                    }
                    if (x < this.width - 1){
                        if (this.__map__[y+1][x+1] == -1){
                            count ++;
                        }
                    } 
                }
                
                if (x > 0){
                    if (this.__map__[y][x-1] == -1){
                        count ++;
                    }
                }
                if (x < this.width - 1){
                    if (this.__map__[y][x+1] == -1){
                        count ++;
                    }
                } 
                this.__map__[y][x] = count;
            }
        }
    }
    
    public int get(int x, int y){
        return this.__map__[y][x];
    }
}
