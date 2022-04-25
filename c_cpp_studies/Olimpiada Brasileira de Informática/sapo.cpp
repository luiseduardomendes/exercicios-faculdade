#include <iostream>
#include <vector>

class Coord{
public:
    Coord(){}
    Coord(int _m, int _n) {
        m = _m;
        n = _n;
    }
    int m, n;
};

class Frog{
    public:
        Frog(){}
        Frog(int _m, int _n){
            pos.m = _m;
            pos.n = _n;
        }

        void move(int _m, int _n){
            pos.m = _m;
            pos.n = _n;
        }

        Coord pos;
};

class Map{
    public:
        Map(){}
        Map(int _m, int _n){
            lines = _m;
            columns = _n;
        }

        bool appendRock(int _m, int _n){
            if (_m >= 1 && _m <= lines && _n >= 1 && _n <= columns){
                rocks.push_back(Coord(_m, _n));
                return true;
            }
            else
                return false;
        }

        std::vector<Coord> rocks;
        int columns, lines;

        bool isRock(int _m, int _n){
            for (int i = 0; i < rocks.size(); i ++)
                if (rocks[i].m == _m && rocks[i].n == _n)
                    return true;
            return false;
        }

        void draw_map(){
            for (int i = 0; i < lines; i ++){
                for (int j = 0; i < columns; i ++){
                    if (isRock(i, j))
                        std::cout << '# ';
                    else
                        std::cout << '_ ';
                }
                std::cout << std::endl;
            }
        }
};

class solver{
public:

    std::vector<Coord> stack_frontier;
    std::vector<Coord> visited_coords;
    Map map;


    solver(Map map_){
        map = map_;
    }


    bool solve_map(Coord frog, Coord goal){
        Coord c;
        int i;
        // append valid elements to stack frontier

        visited_coords.push_back(frog);

        for (i = frog.n - 1; i > 0; i --){
            if (map.isRock(frog.m, i) && !visited(Coord(frog.m, i))){
                stack_frontier.push_back(Coord(frog.m, i));
                break;
            }
        }
        // looks to right until find a rock
        for (i = frog.n + 1; i <= map.columns; i ++){
            if (map.isRock(frog.m, i) && !visited(Coord(frog.m, i))){
                stack_frontier.push_back(Coord(frog.m, i));
                break;
            }
        }
        // looks upwards until find a rock
        for (i = frog.m - 1; i > 0; i --){
            if (map.isRock(i, frog.n) && !visited(Coord(i, frog.n))){
                stack_frontier.push_back(Coord(i, frog.n));
                break;
            }
        }
        // looks downwards until find a rock
        for (i = frog.m + 1; i <= map.lines; i ++){
            if (map.isRock(i, frog.n) && !visited(Coord(i, frog.n))){
                stack_frontier.push_back(Coord(i, frog.n));
                break;
            }
        }
        
        for (i = 0; i < stack_frontier.size(); i ++){
            printf("%d, %d\t", stack_frontier[i].m, stack_frontier[i].n);
        }
        printf("\n");
        getchar();

        // verify each of them
        // call recursively the solve_map function

        if (stack_frontier.empty())
            return false;
        else{
            // return the top of the stack frontier
            c = stack_frontier.back();
            stack_frontier.pop_back();
            
            if (c.m == goal.m && c.n == goal.n)
                return true;
            else
                return solve_map(c, goal);
        }

        // if stack is empty, then theres no solution
        // if the goal is reached, theres solution
        printf("Hello2\n");
    }

    bool visited(Coord c){
        int i;
        for (i = 0; i < visited_coords.size(); i ++)
            if (c.m == visited_coords[i].m && c.n == visited_coords[i].n)
                return true;
        return false;
        
    }

};
int main(){    
    Map map = Map(4,5);
    
    map.appendRock(2,1);
    map.appendRock(2,5);
    map.appendRock(4,1);
    map.appendRock(3,4);
    map.appendRock(4,3);
    map.appendRock(4,5);

    solver s = solver(map);

    printf("Hello\n");
    map.draw_map();

    if (s.solve_map(Coord(3,4),Coord(2,1    )))
        printf("Possible!\n");
    else
        printf("Impossible\n");

    return 0;
}