#include "Champions.hpp"


bool Champions::isTopLane(){
    for(int i = 0; i < 5; i++)
        if (dataChampion.roleChampion[i] == TOPLANE)
            return true;
    return false;
}
bool Champions::isJungle(){
    for(int i = 0; i < 5; i++)
        if (dataChampion.roleChampion[i] == JUNGLE)
            return true;
    return false;
}
bool Champions::isMidLane(){
    for(int i = 0; i < 5; i++)
        if (dataChampion.roleChampion[i] == MIDLANE)
            return true;
    return false;
}
bool Champions::isAdCarry(){
    for(int i = 0; i < 5; i++)
        if (dataChampion.roleChampion[i] == ADCARRY)
            return true;
    return false;
}
bool Champions::isSupport(){
    for(int i = 0; i < 5; i++)
        if (dataChampion.roleChampion[i] == SUPPORT)
            return true;
    return false;
}

bool Champions::isRogue(){
    for(int i = 0; i < 6; i++)
        if (dataChampion.classChampion[i] == ROGUE)
            return true;
    return false;
}
bool Champions::isFighter(){
    for(int i = 0; i < 6; i++)
        if (dataChampion.classChampion[i] == FIGHTER)
            return true;
    return false;
}
bool Champions::isMage(){
    for(int i = 0; i < 6; i++)
        if (dataChampion.classChampion[i] == MAGE)
            return true;
    return false;
}
bool Champions::isMarksman(){
    for(int i = 0; i < 6; i++)
        if (dataChampion.classChampion[i] == MARKSMAN)
            return true;
    return false;
}
bool Champions::isControll(){
    for(int i = 0; i < 6; i++)
        if (dataChampion.classChampion[i] == CONTROLL)
            return true;
    return false;
}
bool Champions::isTank(){
    for(int i = 0; i < 6; i++)
        if (dataChampion.classChampion[i] == TANK)
            return true;
    return false;
}

void Champions::createChampion(std::string name){
    dataChampion.nameChampion = name;
    for (int i = 0; i < 5; i++){
        dataChampion.roleChampion[i] = -1; 
    }
    for (int i = 0; i < 6; i++){
        dataChampion.classChampion[i] = -1;
    }
}

void Champions::addClassChampion(int classChamp){
    for (int i = 0; i < 6; i++)
        if (dataChampion.classChampion[i] == -1)
            dataChampion.classChampion[i] = classChamp;
}

void Champions::addRoleChampion(int roleChamp){
    for (int i = 0; i < 5; i++)
        if (dataChampion.roleChampion[i] == -1)
            dataChampion.roleChampion[i] = roleChamp;
}