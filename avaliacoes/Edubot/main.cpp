#include <iostream>
#include <cstdlib>
#include <math.h>
#include "libs/EdubotLib.hpp"

using namespace std;
enum {RIGHT = 6, MID = 3, LEFT = 0};

void rotateRight(int* wallDirect, EdubotLib **edubotLib);
void rotateLeft(int* wallDirect, EdubotLib **edubotLib);
void endOfWall(int direct, EdubotLib **edubotLib);

int main(){

	EdubotLib *edubotLib = new EdubotLib();
	
	int flag = 1;
	int i, count = 0;
	int wallDirect;
	
	//try to connect on robot
	if(edubotLib->connect()) {
		wallDirect = RIGHT;
		edubotLib->sleepMilliseconds(1000);
		while (edubotLib->isConnected()) {
			edubotLib->move(0.2);
			
			
			if (count == 0){
				while(edubotLib->getSonar(MID) >= 0.065)
					edubotLib->sleepMilliseconds(1);
				
				if (edubotLib->getSonar(RIGHT) > edubotLib->getSonar(LEFT)) {
					rotateRight(&wallDirect, &edubotLib);
					
					wallDirect = LEFT;
					
					
					
				}
				else{			
					rotateLeft(&wallDirect, &edubotLib);
					wallDirect = RIGHT;
					
					
				}
			}
			edubotLib->move(0.3);
			while(edubotLib->getSonar(MID) >= 0.065 && edubotLib->getSonar(wallDirect) <= 0.25)
				edubotLib->sleepMilliseconds(1);
			if(edubotLib->getSonar(MID) < 0.25){
				if(edubotLib->getSonar(RIGHT) > edubotLib->getSonar(LEFT)){
					rotateRight(&wallDirect, &edubotLib);
					count ++;
				}
				else{
					rotateLeft(&wallDirect, &edubotLib);
					count --;
				}
				
			}
			else if (edubotLib->getSonar(wallDirect) > 0.25){
				endOfWall(wallDirect, &edubotLib);
				
				
			}
			
				
			
			
			
		}
		edubotLib->disconnect();
	}
	else{
		cout << "Could not connect on robot!" << endl;
	}

	return 0;
}

void rotateRight(int* wallDirect, EdubotLib **edubotLib){
	
	(*edubotLib)->rotate(90);
	(*edubotLib)->sleepMilliseconds(1500);
}

void rotateLeft(int* wallDirect, EdubotLib **edubotLib){
	
	(*edubotLib)->rotate(-90);
	(*edubotLib)->sleepMilliseconds(1500);
}

void endOfWall(int direct, EdubotLib **edubotLib){
	int flag = -1;
	if (direct == RIGHT)
		flag = 1;
	
	(*edubotLib)->sleepMilliseconds(750);
 	(*edubotLib)->stop();
 	(*edubotLib)->rotate(90 * flag);
 	(*edubotLib)->sleepMilliseconds(1500);
 	(*edubotLib)->move(0.3);
 	(*edubotLib)->sleepMilliseconds(1500);
 	
}

