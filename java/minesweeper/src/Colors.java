import java.util.Random;

public class Colors {
    // Reset
    public static  String ANSI_RESET = "\u001B[0m";

    // Regular Colors
    public static  String ANSI_BLACK = "\u001B[30m";
    public static  String ANSI_RED = "\u001B[31m";
    public static  String ANSI_GREEN = "\u001B[32m";
    public static  String ANSI_YELLOW = "\u001B[33m";
    public static  String ANSI_BLUE = "\u001B[34m";
    public static  String ANSI_PURPLE = "\u001B[35m";
    public static  String ANSI_CYAN = "\u001B[36m";
    public static  String ANSI_WHITE = "\u001B[37m"; 

    // Bold
    public static  String BLACK_BOLD = "\033[1;30m";  // BLACK
    public static  String RED_BOLD = "\033[1;31m";    // RED
    public static  String GREEN_BOLD = "\033[1;32m";  // GREEN
    public static  String YELLOW_BOLD = "\033[1;33m"; // YELLOW
    public static  String BLUE_BOLD = "\033[1;34m";   // BLUE
    public static  String PURPLE_BOLD = "\033[1;35m"; // PURPLE
    public static  String CYAN_BOLD = "\033[1;36m";   // CYAN
    public static  String WHITE_BOLD = "\033[1;37m";  // WHITE

    // Underline
    public static  String BLACK_UNDERLINED = "\033[4;30m";  // BLACK
    public static  String RED_UNDERLINED = "\033[4;31m";    // RED
    public static  String GREEN_UNDERLINED = "\033[4;32m";  // GREEN
    public static  String YELLOW_UNDERLINED = "\033[4;33m"; // YELLOW
    public static  String BLUE_UNDERLINED = "\033[4;34m";   // BLUE
    public static  String PURPLE_UNDERLINED = "\033[4;35m"; // PURPLE
    public static  String CYAN_UNDERLINED = "\033[4;36m";   // CYAN
    public static  String WHITE_UNDERLINED = "\033[4;37m";  // WHITE

    // Background
    public static  String BLACK_BACKGROUND = "\033[40m";  // BLACK
    public static  String RED_BACKGROUND = "\033[41m";    // RED
    public static  String GREEN_BACKGROUND = "\033[42m";  // GREEN
    public static  String YELLOW_BACKGROUND = "\033[43m"; // YELLOW
    public static  String BLUE_BACKGROUND = "\033[44m";   // BLUE
    public static  String PURPLE_BACKGROUND = "\033[45m"; // PURPLE
    public static  String CYAN_BACKGROUND = "\033[46m";   // CYAN
    public static  String WHITE_BACKGROUND = "\033[47m";  // WHITE

    // High Intensity
    public static  String BLACK_BRIGHT = "\033[0;90m";  // BLACK
    public static  String RED_BRIGHT = "\033[0;91m";    // RED
    public static  String GREEN_BRIGHT = "\033[0;92m";  // GREEN
    public static  String YELLOW_BRIGHT = "\033[0;93m"; // YELLOW
    public static  String BLUE_BRIGHT = "\033[0;94m";   // BLUE
    public static  String PURPLE_BRIGHT = "\033[0;95m"; // PURPLE
    public static  String CYAN_BRIGHT = "\033[0;96m";   // CYAN
    public static  String WHITE_BRIGHT = "\033[0;97m";  // WHITE

    // Bold High Intensity
    public static  String BLACK_BOLD_BRIGHT = "\033[1;90m"; // BLACK
    public static  String RED_BOLD_BRIGHT = "\033[1;91m";   // RED
    public static  String GREEN_BOLD_BRIGHT = "\033[1;92m"; // GREEN
    public static  String YELLOW_BOLD_BRIGHT = "\033[1;93m";// YELLOW
    public static  String BLUE_BOLD_BRIGHT = "\033[1;94m";  // BLUE
    public static  String PURPLE_BOLD_BRIGHT = "\033[1;95m";// PURPLE
    public static  String CYAN_BOLD_BRIGHT = "\033[1;96m";  // CYAN
    public static  String WHITE_BOLD_BRIGHT = "\033[1;97m"; // WHITE

    // High Intensity backgrounds
    public static  String BLACK_BACKGROUND_BRIGHT = "\033[0;100m";// BLACK
    public static  String RED_BACKGROUND_BRIGHT = "\033[0;101m";// RED
    public static  String GREEN_BACKGROUND_BRIGHT = "\033[0;102m";// GREEN
    public static  String YELLOW_BACKGROUND_BRIGHT = "\033[0;103m";// YELLOW
    public static  String BLUE_BACKGROUND_BRIGHT = "\033[0;104m";// BLUE
    public static  String PURPLE_BACKGROUND_BRIGHT = "\033[0;105m"; // PURPLE
    public static  String CYAN_BACKGROUND_BRIGHT = "\033[0;106m";  // CYAN
    public static  String WHITE_BACKGROUND_BRIGHT = "\033[0;107m";   // WHITE

    public static  String[] mapStrings = {
        BLUE_BOLD,
        GREEN_BOLD,
        RED_BOLD,
        PURPLE_BOLD,
        YELLOW_BOLD,
        CYAN_BOLD,
        RED_BOLD,
        PURPLE_BOLD
    };

    public static  String[] mapBG = {
        BLACK_BACKGROUND,
        RED_BACKGROUND,
        GREEN_BACKGROUND,
        YELLOW_BACKGROUND,
        BLUE_BACKGROUND,
        PURPLE_BACKGROUND,
        CYAN_BACKGROUND,
        BLACK_BACKGROUND_BRIGHT,
        RED_BACKGROUND_BRIGHT,
        GREEN_BACKGROUND_BRIGHT,
        YELLOW_BACKGROUND_BRIGHT,
        BLUE_BACKGROUND_BRIGHT,
        PURPLE_BACKGROUND_BRIGHT,
        CYAN_BACKGROUND_BRIGHT,
    };

    public static String random_bg(){
        Random generator = new Random();

        return mapBG[generator.nextInt(14)];
    }

    public static String chess_grass(int i){
        if (i % 2 == 0){
            return BLUE_BACKGROUND_BRIGHT;
        } 
        else{
            return BLUE_BACKGROUND;
        }

    }
    public static String chess_open(int i){
        if (i % 2 == 0){
            return BLACK_BACKGROUND;
        } 
        else{
            return BLACK_BACKGROUND;
        }

    }
}
