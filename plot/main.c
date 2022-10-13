#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

double t = 0;

void display_result(double center_x, double center_y, int size_w, int size_h, double lim_w, double lim_h);
double f(double x);
double f_1(double y);
int main(){
	double center_x = 0, center_y = 0, lim_w = 10, lim_h = 10;
	char input = 'a' ;
	int run = 1;
	struct winsize w;
	
	lim_w = 6.28;
	
	while(run){
		system("clear");
		ioctl(0, TIOCGWINSZ, &w);

    	double size_h = w.ws_row;
    	double size_w = w.ws_col / 2;

		lim_h = size_h * lim_w / (2*size_w);

		

		int interp = 5;
		display_result(center_x, center_y, size_w, size_h, lim_w, lim_h);
		scanf("%c", &input);
		switch(input){
			case '+':
				lim_w *= 1.1;
				lim_h *= 1.1;
				break;
			case '-':
				lim_w *= 0.9;
				lim_h *= 0.9;
				break;
			case ' ':
				run = 0;
				break;
			case 's':
				center_y -= lim_h / size_h;
				break;
			case 'w':
				center_y += lim_h / size_h;
				break;
			case 'a':
				center_x -= lim_w / size_w;
				break;
			case 'd':
				center_x += lim_w / size_w;
				break;

		}
	}
	
	return 0;
}		

void display_result(double center_x, double center_y, int size_w, int size_h, double lim_w, double lim_h){
	double x, y;
	int i, j;
	double inc_x = lim_w / double(size_w), inc_y = lim_h / double(size_h);
	
	for (i = size_h-1; i >= 0; i --){
		y = center_y - (lim_h / 2) + inc_y * i;
		for (j = 0; j < size_w; j ++){
			x = center_x - (lim_w / 2) + inc_x * j;
			if (abs(f(x) - y) < inc_y / 2){
				printf("# ");
			}
			else if (abs(f_1(y) - x) < inc_x / 2){
				printf("# ");
			}
			else if(abs(y) < inc_y / 2){
				if(abs(x - round(x)) < inc_x / 2){
					printf("+-");
				}	
				else {
					printf("--");
				}
			}
			else if(abs(x) < inc_x / 2){
				if(abs(y - round(y)) < inc_y / 2){
					printf("+ ");
				}	
				else {
					printf("| ");
				}
			}
			else if(abs(y - round(y)) < inc_y / 2){
				printf(". ");
			}
			else if(abs(x - round(x)) < inc_x / 2){
				printf(". ");
			}	
			else{
				printf("  "); 
			}
		}
		printf("\n");
	}

}

double f(double x){
//	return pow(2, x);
//	return sqrt(9 - x*x);
	return cos(x + t);
}
double f_1(double y){
//	return log2(y);
//	return sqrt(9 - y*y);
	return acos(y) - t;
}

