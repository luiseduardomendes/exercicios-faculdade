import java.util.Scanner;

public class Menu {
    public Game game;
    public Boolean ended = false;
    private String input = new String();
    Scanner sc = new Scanner(System.in);

    private final float[] dific = {
        0.1f,
        0.2f,
        0.4f
    };

    private final int[] size = {
        10,
        20,
        40
    };

    private int cursor = 0;
    private int current_menu = 0;
    private int select_size = 10;
    
    public Menu(){}

    public void cursor_down(){
        cursor ++;
    }

    public void cursor_up(){
        cursor --;
    }

    public void select(){
        switch(current_menu){
            case 0:{ // main menu
                switch(cursor){
                    case 0: // new game
                        current_menu ++;
                        break;
                    case 1:
                        break;
                    case 2:
                        ended = true;
                        break;
                }
                break;
            }
            case 1:{ // size menu
                select_size = size[cursor];
                current_menu ++;
                break;
            }
            case 2:{ // dificulty menu
                System.out.println(select_size);
                game = new Game(select_size, select_size, dific[cursor]);
                run_game();
                current_menu = 0;
                break;
            }
        }
        cursor = 0;
    }

    public void run(){
        do{
            display_current_menu();
            input = sc.next();
            decodeKeyMenu(input);
        } while(!ended);
    }

    private void run_game(){
        do{
            game.draw();
            input = sc.next();
            decodeKeyGame(input);
        } while(!game.is_game_ended);
        game.draw();
        if(game.winner){
            System.out.println(Colors.GREEN_BACKGROUND);
            System.out.println(" Voce venceu!!");
            System.out.println(Colors.ANSI_RESET);
        }
        else{
            System.out.println(Colors.RED_BACKGROUND);
            System.out.println("Voce Perdeu!!\n");
            System.out.println(Colors.ANSI_RESET);
        }
        input = sc.next();
    }

    private void display_current_menu(){
        System.out.print("\033[H\033[2J");  
        System.out.flush(); 
        switch(current_menu){
            case 0:
                display_main_menu();
                break;
            case 1:
                display_size_menu();
                break;
            case 2:
                display_dific_menu();
                break;
        }
    }

    public void display_main_menu(){
        System.out.println(Colors.GREEN_BACKGROUND);
        System.out.println("CAMPO MINADO\n");
        System.out.println(Colors.ANSI_RESET);

        if (cursor == 0) {System.out.println(Colors.RED_BACKGROUND);}
        System.out.println("Novo jogo");
        if (cursor == 0) {System.out.println(Colors.ANSI_RESET);}

        if (cursor == 1) {System.out.println(Colors.RED_BACKGROUND);}
        System.out.println("Creditos");
        if (cursor == 1) {System.out.println(Colors.ANSI_RESET);}

        if (cursor == 2) {System.out.println(Colors.RED_BACKGROUND);}
        System.out.println("Sair");
        if (cursor == 2) {System.out.println(Colors.ANSI_RESET);}
    }

    public void display_dific_menu(){
        System.out.println(Colors.GREEN_BACKGROUND);
        System.out.println("CAMPO MINADO\n");
        System.out.println(Colors.ANSI_RESET);

        if (cursor == 0) {System.out.println(Colors.RED_BACKGROUND);}
        System.out.println("Facil");
        if (cursor == 0) {System.out.println(Colors.ANSI_RESET);}

        if (cursor == 1) {System.out.println(Colors.RED_BACKGROUND);}
        System.out.println("Medio");
        if (cursor == 1) {System.out.println(Colors.ANSI_RESET);}

        if (cursor == 2) {System.out.println(Colors.RED_BACKGROUND);}
        System.out.println("Dificil");
        if (cursor == 2) {System.out.println(Colors.ANSI_RESET);}
    }

    public void display_size_menu(){
        System.out.println(Colors.GREEN_BACKGROUND);
        System.out.println("CAMPO MINADO\n");
        System.out.println(Colors.ANSI_RESET);

        if (cursor == 0) {System.out.println(Colors.RED_BACKGROUND);}
        System.out.println("10x10");
        if (cursor == 0) {System.out.println(Colors.ANSI_RESET);}

        if (cursor == 1) {System.out.println(Colors.RED_BACKGROUND);}
        System.out.println("20x20");
        if (cursor == 1) {System.out.println(Colors.ANSI_RESET);}

        if (cursor == 2) {System.out.println(Colors.RED_BACKGROUND);}
        System.out.println("40x40");
        if (cursor == 2) {System.out.println(Colors.ANSI_RESET);}
    }
    

    private void decodeKeyGame(String s){
        switch(s){
            case "w": case "W":
            game.cursor_up();
            break;
            case "s": case "S":
            game.cursor_down();
            break;
            case "d": case "D":
            game.cursor_right();
            break;
            case "a": case "A":
            game.cursor_left();
            break;
            case "p": case "P":
            game.flag();
            break;
            case "o": case "O":
            game.open();
            break;
            case "x": case "X":
            game.close();
            break;
        }
    }
    private void decodeKeyMenu(String s){
        switch(s){
            case "w": case "W":
            cursor_up();
            break;
            case "s": case "S":
            cursor_down();
            break;
            case "o": case "O":
            select();
            break;
        }
    }

}
