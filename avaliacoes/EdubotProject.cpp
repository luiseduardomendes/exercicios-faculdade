#include <iostream>
#include <cstdlib>
#include <term.h>
#include "libs/EdubotLib.hpp"

int main(){

	EdubotLib *edubotLib = new EdubotLib();
	
	int flag = 1;
	int i;
	//try to connect on robot
	if(edubotLib->connect()){

		while (flag){
			system("clear");
			if(edubotLib->getSonar(3) >= 0.1){
				std::cout << "sonar 4: " << edubotLib->getSonar(3) << std::endl;
				edubotLib->move(0.1);
				edubotLib->sleepMilliseconds (5);	
			}
			else{
				std::cout << "wall ahead" << std::endl;
				if(edubotLib->getSonar(0) > edubotLib->getSonar(6))
					edubotLib->rotate (-90);
				else
					edubotLib->rotate (90);
				edubotLib->sleepMilliseconds(1500);
			}
			for (i = 0; i < 4; i ++){
				if(edubotLib->getBumper(i)){
					std::cout << "bumper: " << i << std::endl;
					edubotLib->stop();
					flag = 0;
					
				}
			}
			
		}

		edubotLib->disconnect();
	}
	else{
		std::cout << "Could not connect on robot!" << std::endl;
	}

	return 0;
}
