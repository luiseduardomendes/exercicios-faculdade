public class Game {
    private Map map;
    private Player player;
    private Draw draw;

    private int fields_remaining;
    private int mines_remaining;
    private int wrong_flags = 0;

    public Boolean is_game_ended = false;
    public Boolean winner = false;

    private int cursor_x = 0;
    private int cursor_y = 0;

    public Game(int w, int h, double mines){
        this.map = new Map(w, h, mines);
        this.player = new Player(w, h);
        this.draw = new Draw();
        
        this.fields_remaining = w * h - this.map.num_mines;
        this.mines_remaining = this.map.num_mines;
    }

    public Game(){
        this.map = new Map(10, 10, 0.1);
        this.player = new Player(10, 10);
        this.draw = new Draw();
        
        this.fields_remaining = 100 - this.map.num_mines;
        this.mines_remaining = this.map.num_mines;
    }

    public void draw(){
        draw.draw(mines_remaining, fields_remaining, map, player, cursor_x, cursor_y);
    }
    
    public void flag(int x, int y){
        if (this.isValid(x, y)){
            if (player.is_flag(x, y)){
                mines_remaining ++;
                if (!check_flag(x, y)){
                    wrong_flags --;
                }
            }
            else{
                if (!check_flag(x, y)){
                    wrong_flags ++;
                }
                mines_remaining --;
            }
            
            player.change_flag(x, y);

            if (this.mines_remaining == 0 && this.wrong_flags == 0){
                this.revealMines();
                close();
                this.winner = true;
            }
        }
    }
    public void flag(){
        int x = cursor_x;
        int y = cursor_y;
        if (this.isValid(x, y)){
            if (player.is_flag(x, y)){
                mines_remaining ++;
                if (!check_flag(x, y)){
                    wrong_flags --;
                }
            }
            else{
                if (!check_flag(x, y)){
                    wrong_flags ++;
                }
                mines_remaining --;
            }
            
            player.change_flag(x, y);

            if (this.mines_remaining == 0 && this.wrong_flags == 0){
                this.revealMines();
                close();
                this.winner = true;
            }
        }
    }

    public void open(int x, int y){
        if (isValid(x, y) && !player.is_open(x, y) && !player.is_flag(x, y)){
            if (map.get(x, y) != -1){
                if (map.get(x, y) == 0){
                    this.open_rec(x, y);
                }
                else{
                    player.open(x, y);
                    this.fields_remaining --;
                }
                if (this.fields_remaining == 0){
                    this.revealMines();
                    close();
                    this.winner = true;
                }
            }
            else {
                this.revealMines();
                close();
            }
        }
    }
    public void open(){
        int x = cursor_x;
        int y = cursor_y;
        if (isValid(x, y) && !player.is_open(x, y) && !player.is_flag(x, y)){
            if (map.get(x, y) != -1){
                if (map.get(x, y) == 0){
                    this.open_rec(x, y);
                }
                else{
                    player.open(x, y);
                    this.fields_remaining --;
                }
                if (this.fields_remaining == 0){
                    this.revealMines();
                    close();
                    this.winner = true;
                }
            }
            else {
                this.revealMines();
                close();
            }
        }
    }

    private void open_rec(int x, int y){
        this.player.open(x, y);
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

    private Boolean isValid(int x, int y){
        if (x >= 0 && x < this.map.width && y >= 0 && y < this.map.height){
            return true;
        }
        return false;
    }
    
    private void revealMines(){
        for (int y = 0; y < map.height; y ++){
            for (int x = 0; x < map.width; x ++){
                if (map.get(x, y) == -1){
                    player.open(x, y);
                }
            }
        }
    }

    private void set_open_status(int x, int y){
        if (this.isValid(x, y) && !player.is_open(x, y)){
            if (map.get(x, y) == 0){
                this.open_rec(x, y);
            }
            else{
                this.player.open(x, y);
                this.fields_remaining --;
            }
        }
    }

    private Boolean check_flag(int x, int y){ 
        if (this.isValid(x, y) && (map.get(x, y) == -1)){
            return true;
        }
        return false;
    }

    public void cursor_up(){
        cursor_y --;
    }
    public void cursor_down(){
        cursor_y ++;
    }
    public void cursor_left(){
        cursor_x --;
    }
    public void cursor_right(){
        cursor_x ++;
    }

    public void close(){
        is_game_ended = true;
    }
}
