#include <iostream>
#include <cstdlib>
#include "libs/EdubotLib.hpp"

int main(){

	EdubotLib *edubotLib = new EdubotLib();
	
	int flag = 1;
	int i;
	//try to connect on robot
	if(edubotLib->connect()){

		while (1){
			
			edubotLib->move(0.3);
			
			flag = 1;
			do{
				if(edubotLib->getSonar(3) >= 0.1){
					edubotLib->sleepMilliseconds (1);	
				}
				else{
				
					if(edubotLib->getSonar(0) > edubotLib->getSonar(6))
						edubotLib->rotate (-90);
					else
						edubotLib->rotate (90);
					edubotLib->sleepMilliseconds(1500);
					flag = 0;
				}
				for (i = 0; i < 4; i ++){
					if(edubotLib->getBumper(i)){
						edubotLib->stop();
						flag = 0;
					}
				}
			}while (flag == 1);
		}
		edubotLib->disconnect();
	}
	else{
		std::cout << "Could not connect on robot!" << std::endl;
	}

	return 0;
}
