import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Map map;
        String s;
        Boolean cont = true;
        Scanner sc = new Scanner(System.in); 
        int x, y;
        map = new Map(20, 20, 0.1);

        do {
            map.draw();
            s = sc.next();
            x = sc.nextInt();
            y = sc.nextInt();
            if (s.equals("f") || s.equals("F")){
                map.set_flag(x, y);
            }
            else {
                map.open(x, y);
            }
        } while (!map.is_game_ended);
        map.draw();
        if (map.winner){
            System.out.println("Parabens, voce venceu!");
        }
        else{
            System.out.println("Voce perdeu!");
        }
    }
}
