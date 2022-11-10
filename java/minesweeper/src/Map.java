public class Map {
    private int width;
    private int height;

    private int num_mines;
    private int fields_remaining;
    private int mines_remaining;

    private int[][] __map__;
    private Boolean[][] __open__;
    private Boolean[][] __flag__;
    
    public Boolean is_game_ended = false;
    public Boolean winner = false;

    public Map(){
        this.width = 10;
        this.height = 10;
        this.num_mines = 10;
        this.fields_remaining = 100 - this.num_mines;
        this.mines_remaining = this.num_mines;
        
        this.init();
    }

    public Map(int w, int h, double perc_mines){
        this.width = w;
        this.height = h;
        this.num_mines = (int)(w * h * perc_mines);
        this.fields_remaining = w * h - this.num_mines;
        this.mines_remaining = this.num_mines;

        this.init();
    }

    private void init(){
        this.__map__ = new int[this.height][this.width];
        this.__open__ = new Boolean[this.height][this.width];
        this.__flag__ = new Boolean[this.height][this.width];
        
        this.init_array();
        this.init_map();
    }

    private void init_array(){
        for (int y = 0; y < this.height; y ++){
            for (int x = 0; x < this.width; x ++){
                this.__map__[y][x] = 0;
            }
        }
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

    private void init_map(){
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

    private Boolean isValid(int x, int y){
        if (x >= 0 && x < this.width && y >= 0 && y < this.height){
            return true;
        }
        return false;
    }

    public void open(int x, int y){
        if (this.isValid(x, y) && !this.__open__[y][x] && !this.__flag__[y][x]){
            if (this.__map__[y][x] != -1){
                if (this.__map__[y][x] == 0){
                    this.open_rec(x, y);
                }
                else{
                    this.__open__[y+0][x+0] = true;
                    this.fields_remaining --;
                }
                if (this.fields_remaining == 0){
                    this.reveal_mines();
                    this.is_game_ended = true;
                    this.winner = true;
                }
            }
            else {
                this.reveal_mines();
                this.is_game_ended = true;
            }
        }
    }

    private void open_rec(int x, int y){
        this.__open__[y][x] = true;
        this.fields_remaining --;
        this.set_open_status(x+1, y+1);
        this.set_open_status(x+1, y+0);
        this.set_open_status(x+1, y-1);
        this.set_open_status(x+0, y+1);
        this.set_open_status(x+0, y-1);
        this.set_open_status(x-1, y+1);
        this.set_open_status(x-1, y+0);
        this.set_open_status(x-1, y-1);
            
    }

    private void set_open_status(int x, int y){
        if (this.isValid(x, y) && !this.__open__[y][x]){
            if (this.__map__[y][x] == 0){
                this.open_rec(x, y);
            }
            else{
                this.__open__[y][x] = true;
                this.fields_remaining --;
            }
        }
    }

    private void reveal_mines(){
        for (int y = 0; y < this.height; y ++){
            for (int x = 0; x < this.width; x ++){
                if (this.__map__[y][x] == -1){
                    this.__open__[y][x] = true;
                }
            }
        }
    }

    public void set_flag(int x, int y){
        if (this.isValid(x, y)){
            if (this.__flag__[y][x]){
                mines_remaining ++;
            }
            else{
                mines_remaining --;
            }
            this.__flag__[y][x] = !this.__flag__[y][x];
            
        }
    }

    public void draw(){
        System.out.print("\033[H\033[2J");  
        System.out.flush();  

        System.out.printf("*: %d\t#: %d", this.mines_remaining, this.fields_remaining);
        System.out.println();

        System.out.print("   ");
        for (int x = 0; x < this.width; x ++){
            System.out.printf("%3d", x);
        }
        System.out.println();

        System.out.print("    ");
        for (int x = 0; x < this.width; x ++){
            System.out.print("---");
        }
        System.out.println();
        
        for (int y = 0; y < this.height; y ++){
            System.out.printf("%2d", y);
            System.out.print("| ");
            for (int x = 0; x < this.width; x ++){
                if (this.__open__[y][x]){
                    if (this.__map__[y][x] == -1){
                        System.out.print(" * ");
                    }
                    else if (this.__map__[y][x] == 0){
                        System.out.print("   ");
                    }
                    else{
                        System.out.printf("\u001B[4%dm",this.__map__[y][x]);
                        System.out.printf(" %d ", this.__map__[y][x]);
                        System.out.print("\u001B[0m");
                    }
                }
                else{
                    
                    if (this.__flag__[y][x]){
                        System.out.print("\u001B[31m");
                        System.out.print(" P ");
                        System.out.print("\u001B[0m");
                    }
                    else {
                        System.out.print(" _ ");
                    }
                }
            }
            System.out.print("|");
            System.out.printf("%2d", y);
            System.out.println();
        }
        System.out.print("    ");
        for (int x = 0; x < this.width; x ++){
            System.out.print("---");
        }
        System.out.println();
        System.out.print("   ");
        for (int x = 0; x < this.width; x ++){
            System.out.printf("%3d", x);
        }
        System.out.println();
    }
}
