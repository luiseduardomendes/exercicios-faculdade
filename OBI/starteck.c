#include <stdio.h>

int main(){
    int i;
    int N;
    int sheep[1000000];
    int c_star = 1;
    int total_sheep = 0;
    int max_star = 1;

    scanf("%d", &N);

    for (i = 0; i < N; i ++){
        scanf("%d", &(sheep[i]));
        total_sheep += sheep[i];
    }

    while (c_star >= 1 && c_star <= N){
        if (c_star > max_star)
            max_star = c_star;
        if (sheep[c_star - 1] != 0){
            
            total_sheep --;

            if ((sheep[c_star - 1]) % 2 == 0){
                sheep[c_star - 1] --; 
                c_star --;
            }
            else{
                sheep[c_star - 1] --; 
                c_star ++;
            }
        }
        else{
            if ((sheep[c_star - 1]) % 2 == 0){
                c_star --;
            }
            else{
                c_star ++;
            }
        }

        
        
    }
    printf("%d %d\n", max_star, total_sheep);
}