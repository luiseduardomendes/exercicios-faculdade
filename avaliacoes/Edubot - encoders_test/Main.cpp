#include <iostream>
#include "libs/EdubotLib.hpp" 
#include <cmath>
#define NUMBUMPERS 4

using namespace std;

enum {north=90, south=270, east=0, west=180};
enum {bumperActived, timerDown, foundWall, endOfWall, countZero, foundNewWallFollowed};
enum {bumper0 = 0, bumper1, bumper2, bumper3};
enum {leftSonar = 0, midSonar = 3, rightSonar = 6};
enum {backwardMove = 0, forwardMove};

typedef struct {
	double x;
	double y;
}t_vecDist;

typedef struct {
	int type;
	int bumperId;
	int timer;
}t_event;

typedef struct{
	double lastDirection;
	double lastPositionX;
	double lastPositionY;
	int wallFollowed;
	int count;
}t_state;

int testBumpers(EdubotLib *edubotLib);
void moveBackward(EdubotLib *edubotLib, t_event *event, t_state *state, int direction);
void treatColision(EdubotLib *edubotLib, t_event *event, t_state *state);
int waitForEvent(EdubotLib *edubotLib, t_event *event, t_state *state);
void move(EdubotLib *edubotLib, int direction);

int main(){
	
	EdubotLib *edubotLib = new EdubotLib();
	t_event event;
	t_state state;
	int aux;
	
event.timer = 0;
	state.count = 0;
	state.wallFollowed = -1;
	//try to connect on robot
	if(edubotLib->connect()) {
	
		edubotLib->sleepMilliseconds(1500);
		

		do {
			edubotLib->move(0.2);
			while(!waitForEvent(edubotLib, &event, &state));

			switch(event.type){
				case bumperActived:
					treatColision(edubotLib, &event, &state);
					event.type = -1;
					break;
					
				case foundWall:
					if (state.wallFollowed == leftSonar) {
						edubotLib->rotate(90);
						edubotLib->sleepMilliseconds(1500);
						aux = edubotLib->getTheta();
						cout << "getTheta: " << aux << endl;
						state.count ++;
						if ((aux % 90) != 0){
							treatColision(edubotLib, &event, &state);
						}
						
					}
					else {
						edubotLib->rotate(-90);	
						edubotLib->sleepMilliseconds(1500);
						aux = edubotLib->getTheta();
						cout << "getTheta: " << aux << endl;
						state.count --;
						if ((aux % 90) != 0){
							treatColision(edubotLib, &event, &state);
						}
						
					}
					
					event.type = -1;
					break;
				case endOfWall:
					edubotLib->sleepMilliseconds(1000);
					edubotLib->stop();
					if (state.wallFollowed == leftSonar) {
						edubotLib->rotate(-90);
						edubotLib->sleepMilliseconds(1500);
						aux = edubotLib->getTheta();
						cout << "getTheta: " << aux << endl;
						state.count --;
						if ((aux % 90) != 0){
							treatColision(edubotLib, &event, &state);
						}
						
					}
					else {
						edubotLib->rotate(90);	
						edubotLib->sleepMilliseconds(1500);
						aux = edubotLib->getTheta();
						cout << "getTheta: " << aux << endl;
						if ((aux % 90) != 0){
							treatColision(edubotLib, &event, &state);
						}
						state.count ++;
					}
					
					edubotLib->move(0.2);
					edubotLib->sleepMilliseconds(1500);
					event.type = -1;
					break;
				case countZero:
					state.wallFollowed = -1;
					event.type = -1;
					break;
				case foundNewWallFollowed:
					
					if (edubotLib->getSonar(rightSonar) > edubotLib->getSonar(leftSonar)) {						
						state.wallFollowed = leftSonar;
						edubotLib->rotate(90);
						edubotLib->sleepMilliseconds(1500);
						aux = edubotLib->getTheta();
						cout << "getTheta: " << aux << endl;
						state.count ++;
						if ((aux % 90) != 0){
							treatColision(edubotLib, &event, &state);
						}
						
					}
					else{
						state.wallFollowed = rightSonar;
						edubotLib->rotate(-90);
						edubotLib->sleepMilliseconds(1500);
						aux = edubotLib->getTheta();
						cout << "getTheta: " << aux << endl;
						state.count --;
						if ((aux % 90) != 0){
							treatColision(edubotLib, &event, &state);
						}
						
					}		
					event.type = -1;
					break;		
			}
		}while(edubotLib->getX() > -2.0);
		edubotLib->stop();
		edubotLib->disconnect();
	}
	else{
		std::cout << "Could not connect on robot!" << std::endl;
	}

	return 0;
}

void treatColision(EdubotLib *edubotLib, t_event *event, t_state *state){
	
	
	switch (testBumpers(edubotLib)){
		case bumper0:
		case bumper1:
			move(edubotLib, backwardMove);
			break;
		case bumper2:
		case bumper3:
			move(edubotLib, forwardMove);
			break;	
	}
	
	edubotLib->rotate(90);
	edubotLib->sleepMilliseconds(1500);
	state->wallFollowed = -1;
	state->count = 0;
	event->type = -1;
}

void move(EdubotLib *edubotLib, int direction){
	int auxRotate;
	if (direction == backwardMove)
		edubotLib->move(-0.1);
	else{
		edubotLib->move(0.1);
	}
	edubotLib->sleepMilliseconds(500);
	if (((int)edubotLib->getTheta() % 90) - 45 >= 0){
		auxRotate = -1;
	}
	else{
		auxRotate = 1;
	}
	while((int)edubotLib->getTheta() % 90 != 0 && testBumpers(edubotLib) == -1){
		edubotLib->rotate(auxRotate);
		edubotLib->sleepMilliseconds(1500);
		
	}
	
	edubotLib->stop();
}

int testBumpers(EdubotLib *edubotLib){
	for (int i = 0; i < NUMBUMPERS; i ++){
		if (edubotLib->getBumper(i)){
			return i;
		}
	}
	return -1;
}

int waitForEvent(EdubotLib *edubotLib, t_event *event, t_state *state){
	event->bumperId = testBumpers(edubotLib);
	
	if (event->timer > 0){
		event->timer --;
		if (event->timer == 0){
			event->type = timerDown;
			return 1;
		}
	}
	
	if (event->bumperId != -1){
		event->type = bumperActived;
		return 1;
	}
	
	if (edubotLib->getSonar(midSonar) <= 0.06){
		if (state->count != 0)
			event->type = foundWall;
		else
			event->type = foundNewWallFollowed;
			
		return 1;
	}

	if (abs(edubotLib->getSonar(state->wallFollowed)) >= 0.15 && state->wallFollowed != -1) {
		event->type = endOfWall;
		return 1;
	}
		

	if(state->count == 0 && state->wallFollowed != -1) {
		event->type = countZero; 
		return 1;
	}
	
	edubotLib->sleepMilliseconds(50);
	return 0;
}


