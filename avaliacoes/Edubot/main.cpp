#include <iostream>
#include <cstdlib>
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
		while (edubotLib->isConnected()) {
			edubotLib->move(0.3);
			flag = 1;
			do{
				edubotLib->sleepMilliseconds(2);
				cout << "sonar meio " << edubotLib->getSonar(MID) << endl;
				if (edubotLib->getSonar(MID) >= 0.25){
					
					 edubotLib->sleepMilliseconds(2);
					 if (edubotLib->getSonar(wallDirect) > 0.5){
					 	cout << "sonar " << edubotLib->getSonar(wallDirect) << endl;
					 	if(wallDirect == RIGHT){
						 	endOfWall(RIGHT, &edubotLib);
						 	count ++;
						 	flag = 0;
						 }
						 else{
						 	endOfWall(LEFT, &edubotLib);
						 	count --;
						 	flag = 0;
						 }
					 }
					 else{
					 	edubotLib->sleepMilliseconds(2);
					 }
				}
				else if (edubotLib->getSonar(MID) < 0.25){
					if (edubotLib->getSonar(RIGHT) > edubotLib->getSonar(LEFT)) {
						rotateRight(&wallDirect, &edubotLib);
						count ++;
						flag = 0;
					}
					else{			
						rotateLeft(&wallDirect, &edubotLib);
						count --;
						flag = 0;
					}
				}
				cout << "contador: " << count << endl;
				if (count == 0){
					edubotLib->disconnect();
					
				}
			} while (flag);
			
			
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
	int flag = 0;
	if (direct == RIGHT)
		flag = 1;
	
	(*edubotLib)->sleepMilliseconds(750);
 	(*edubotLib)->stop();
 	(*edubotLib)->rotate(90 * flag);
 	(*edubotLib)->sleepMilliseconds(1500);
 	(*edubotLib)->move(0.3);
 	(*edubotLib)->sleepMilliseconds(1500);
}

