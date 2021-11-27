#pragma once
#define NUMCHAMPIONS 150
#include <iostream>

enum{TOPLANE, JUNGLE, MIDLANE, ADCARRY, SUPPORT};
enum{ROGUE, MAGE, FIGHTER, MARKSMAN, CONTROLL, TANK};

typedef struct {
    std::string nameChampion;
    int classChampion[6];
    int roleChampion[5];
}t_dataChampion;

class Champions{
private:
    t_dataChampion dataChampion;
public:
    void createChampion(std::string name);
    void addClassChampion(int classChamp);
    void addRoleChampion(int roleChamp);

    bool isTopLane();
    bool isJungle();
    bool isMidLane();
    bool isAdCarry();
    bool isSupport();

    bool isRogue();
    bool isMage();
    bool isFighter();
    bool isMarksman();
    bool isControll();
    bool isTank();
};