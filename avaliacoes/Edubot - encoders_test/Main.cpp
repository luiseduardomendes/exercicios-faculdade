#include <iostream>
#include "libs/EdubotLib.hpp" 
#include <cmath>
#define NUMBUMPERS 4

using namespace std;

enum {north=90, south=270, east=0, west=180};
enum {bumperActived, timerDown, foundWall, endOfWall, countZero, foundNewWallFollowed};
enum {bumper0 = 0, bumper1, bumper2, bumper3};
enum {leftSonar = 0, midSonar = 3, rightSonar = 6};

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
void moveBackward(EdubotLib *edubotLib, t_event *event, t_state *state, t_vecDist *vecDist);
void treatColision(EdubotLib *edubotLib, t_event *event, t_state *state);
int waitForEvent(EdubotLib *edubotLib, t_event *event, t_state *state);

int main(){
	
	EdubotLib *edubotLib = new EdubotLib();
	t_event event;
	t_state state;
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
						state.count ++;
					}
					else {
						edubotLib->rotate(-90);	
						state.count --;
					}
					edubotLib->sleepMilliseconds(1500);
					event.type = -1;
					break;
				case endOfWall:
					edubotLib->sleepMilliseconds(1000);
					edubotLib->stop();
					if (state.wallFollowed == leftSonar) {
						edubotLib->rotate(-90);
						state.count --;
					}
					else {
						edubotLib->rotate(90);	
						state.count ++;
					}
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
						state.count ++;
					}
					else{
						state.wallFollowed = rightSonar;
						edubotLib->rotate(-90);
						state.count --;
					}		
					event.type = -1;
					break;		
			}
		}while(abs(edubotLib->getX() < 2.5));
		
	}
	else{
		std::cout << "Could not connect on robot!" << std::endl;
	}

	return 0;
}

void treatColision(EdubotLib *edubotLib, t_event *event, t_state *state){
	state->lastPositionX = edubotLib->getX();
	state->lastPositionY = edubotLib->getY();
	state->lastDirection = edubotLib->getTheta();
	t_vecDist *vecDist;
	
	
	switch((int)state->lastDirection){
		case north:
			vecDist->y = -0.1;
			vecDist->x = 0.0;
			break;
		case south:
			vecDist->y = 0.1;
			vecDist->x = 0.0;
			break;
		case east:
			vecDist->y = 0.0;
			vecDist->x = -0.1;
			break;
		case west:
			vecDist->y = 0.0;
			vecDist->x = 0.1;
			break;
		default:
			vecDist->y = sin(state->lastDirection)*(-0.1);
			vecDist->x = cos(state->lastDirection)*(-0.1); 
			//treatAngularPosition(edubotLib, event, state);
			break;
	}
	moveBackward(edubotLib, event, state, vecDist);
	edubotLib->rotate(90);
	edubotLib->sleepMilliseconds(1500);
	event->type = -1;
}

void moveBackward(EdubotLib *edubotLib, t_event *event, t_state *state, t_vecDist *vecDist){
	edubotLib->move(-0.1);
	edubotLib->sleepMilliseconds(700);
	cout << "distx: " << abs(edubotLib->getX() - (state->lastPositionX + vecDist->x)) << endl;
	cout << "disty: " << abs(edubotLib->getY() - (state->lastPositionY + vecDist->y)) << endl;
	while (abs(edubotLib->getX() - (state->lastPositionX + vecDist->x)) >= 0.025 && abs(edubotLib->getY() - (state->lastPositionY + vecDist->y)) >= 0.025){
		//waitForEvent(edubotLib, event, state);
		cout << "distx: " << abs(edubotLib->getX() - (state->lastPositionX + vecDist->x)) << endl;
		cout << "disty: " << abs(edubotLib->getY() - (state->lastPositionY + vecDist->y)) << endl;
		edubotLib->sleepMilliseconds(50);
	}
	edubotLib->stop();
}

void treatCountZero(EdubotLib *edubotLib, t_event *event, t_state *state, t_vecDist *vecDist){
	
}

int testBumpers(EdubotLib *edubotLib){
	for (int i = 0; i < NUMBUMPERS; i ++){
		if (edubotLib->getBumper(i)){
			return i;
		}
		else{
			return -1;
		}
	}
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
		event->type = foundWall;
		return 1;
	}

	if (edubotLib->getSonar(state->wallFollowed) >= 0.15 && state->wallFollowed != -1){
		if (state->wallFollowed != -1){
			event->type = endOfWall;
			return 1;
		}
		else{
			event->type = foundNewWallFollowed;
			return 1;
		}
		
	}

	if(state->count == 0 && state->wallFollowed != -1){
		event->type = countZero; 
		return 1;
	}

	
	edubotLib->sleepMilliseconds(100);
	return 0;
}
