public class Draw { 
    
    public void terminalDraw(int mines, int fields, Map map, Player player){
        System.out.print("\033[H\033[2J");  
        System.out.flush();  

        

        System.out.print("\u001B[32m");
        System.out.printf(" *: %d", mines);
        for (int x = 0; x < map.width - 1; x ++){
            System.out.print("   ");
        }
        System.out.printf("#: %d", fields);
        System.out.print("\u001B[0m");
        System.out.println();
        System.out.println();

        System.out.print("   ");
        System.out.print("\u001B[33m");
        for (int x = 0; x < map.width; x ++){
            System.out.printf("%3d", x);
        }
        System.out.println("\u001B[0m");

        System.out.print("    ");
        for (int x = 0; x < map.width; x ++){
            System.out.print("---");
        }
        System.out.println();
        
        for (int y = 0; y < map.height; y ++){
            System.out.print("\u001B[33m");
            System.out.printf("%2d ", y);
            System.out.print("\u001B[0m");
            System.out.print("|");
            for (int x = 0; x < map.width; x ++){
                if (player.is_open(x, y)){
                    if (map.get(x, y) == -1){
                        System.out.print(" * ");
                    }
                    else if (map.get(x, y) == 0){
                        System.out.print("   ");
                    }
                    else{
                        System.out.printf("\u001B[4%dm", map.get(x, y));
                        System.out.printf(" %d ", map.get(x, y));
                        System.out.print("\u001B[0m");
                    }
                }
                else{
                    if (player.is_flag(x, y)){
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
            System.out.print("\u001B[33m");
            System.out.printf("%2d", y);
            System.out.println("\u001B[0m");
        }
        System.out.print("    ");
        for (int x = 0; x < map.width; x ++){
            System.out.print("---");
        }
        System.out.println();
        System.out.print("   ");
        System.out.print("\u001B[33m");
        for (int x = 0; x < map.width; x ++){
            System.out.printf("%3d", x);
        }
        System.out.println("\u001B[0m");
    }

    public void draw(int mines, int fields, Map map, Player player, int cursor_x, int cursor_y){
        System.out.print("\033[H\033[2J");  
        System.out.flush();  
        
        __draw_interface__(mines, fields, map);
        __draw_x_axis__(map.height);
        __draw_h_line__(map.width);

        for (int y = 0; y < map.height; y ++){
            __draw_y_axis__(y);
            System.out.print(Colors.YELLOW_BACKGROUND_BRIGHT);
            System.out.print(" | ");
            System.out.print(Colors.ANSI_RESET);

            for (int x = 0; x < map.width; x ++){
                __draw_cell__(x, y, map, player, cursor_x, cursor_y);
            }
            System.out.print(Colors.YELLOW_BACKGROUND_BRIGHT);
            System.out.print(" | ");
            System.out.print(Colors.ANSI_RESET);
            __draw_y_axis__(y);

            System.out.println();
        }
        
        __draw_h_line__(map.width);
        __draw_x_axis__(map.height);
    }

    private void __draw_cell__(int x, int y, Map map, Player player, int cursor_x, int cursor_y){
        
        if (cursor_x != x || cursor_y != y){
            if (player.is_open(x, y)){
                if (map.get(x, y) == -1){
                    System.out.print(
                        Colors.WHITE_BOLD +
                        Colors.random_bg() + 
                        " * " + 
                        Colors.ANSI_RESET
                    );
                }
                else if (map.get(x, y) == 0){
                    System.out.print(
                        Colors.chess_open(x + y) +
                        "   " +
                        Colors.ANSI_RESET
                    );
                }
                else{
                    System.out.printf("%s%s %d %s",
                        Colors.chess_open(x + y),
                        Colors.mapStrings[map.get(x, y)], 
                        map.get(x, y), 
                        Colors.ANSI_RESET
                    );
                }
            }
            else{
                if (player.is_flag(x, y)){
                    System.out.print(
                        Colors.chess_grass(x+y) +
                        " P " + 
                        Colors.ANSI_RESET
                    );
                }
                else {
                    System.out.print(
                        Colors.chess_grass(x+y) +
                        "   " + 
                        Colors.ANSI_RESET
                    );
                }
            }
        }
        else{
            if (player.is_open(x, y)){
                if (map.get(x, y) == -1){
                    System.out.print(
                        Colors.WHITE_BOLD +
                        Colors.random_bg() + 
                        " * " + 
                        Colors.ANSI_RESET
                    );
                }
                else if (map.get(x, y) == 0){
                    System.out.print(
                        Colors.RED_BACKGROUND +
                        " + " +
                        Colors.ANSI_RESET
                    );
                }
                else{
                    System.out.printf("%s %d %s",
                        Colors.RED_BACKGROUND,
                        map.get(x, y), 
                        Colors.ANSI_RESET
                    );
                }
            }
            else{
                if (player.is_flag(x, y)){
                    System.out.print(
                        Colors.GREEN_BACKGROUND +
                        " P " + 
                        Colors.ANSI_RESET
                    );
                }
                else {
                    System.out.print(
                        Colors.GREEN_BACKGROUND +
                        " + " + 
                        Colors.ANSI_RESET
                    );
                }
            }
        }
    }

    private void __draw_interface__(int mines, int fields, Map map){
        System.out.printf("%s *: %s%d %s", Colors.RED_BACKGROUND, Colors.RED_BOLD, mines, Colors.ANSI_RESET);
        for (int x = 0; x < map.width-1; x ++){
            System.out.print("   ");
        }
        System.out.print("  ");
        System.out.printf("%s #: %s%d %s\n\n", Colors.RED_BACKGROUND, Colors.RED_BOLD, fields, Colors.ANSI_RESET);
    }

    private void __draw_y_axis__(int y){
        System.out.print(Colors.RED_BACKGROUND);
        System.out.printf("%2d ", y);
        System.out.print(Colors.ANSI_RESET);
    }

    private void __draw_x_axis__(int width){
        System.out.print("      ");
        System.out.print(Colors.RED_BACKGROUND);
        for (int x = 0; x < width; x ++){
            System.out.printf("%2d ", x);
        }
        System.out.print(Colors.ANSI_RESET);
        System.out.println();
    }

    private void __draw_h_line__(int width){
        System.out.print("   ");
        System.out.print(Colors.YELLOW_BACKGROUND_BRIGHT);
        System.out.print(" +-");
        for (int x = 0; x < width; x ++){
            System.out.printf("---", x);
        }
        System.out.println("-+ ");
        System.out.print(Colors.ANSI_RESET);
    }

}
