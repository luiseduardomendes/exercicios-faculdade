#include <iostream>
#include "Champions.h"

int main(){
    std::string nameChampion[NUMCHAMPIONS] = {{"Aphelios"},{"Ashe"},{"Caitlyn"},{"Draven"},{"Ezreal"},{"Jhin"},{"Jinx"},
    {"Kai'sa"},{"Kalista"},{"Kog'Maw"},{"Lucian"},{"Miss Fortune"},{"Samira"},{"Senna"},{"Sivir"},{"Tristana"},{"Twitch"},
    {"Varus"},{"Vayne"},{"Xayah"},{"Ahri"},{"Akali"},{"Anivia"},{"Annie"},{"Aurelion Sol"},{"Azir"},{"Cassiopeia"},
    {"Corki"},{"Diana"},{"Ekko"},{"Fizz"},{"Heimerdinger"},{"Irelia"},{"Kassadin"},{"Katarina"},{"LeBlanc"},{"Lissandra"},
    {"Lucian"},{"Lux"},{"Malzahar"},{"Neeko"},{"Orianna"},{"Pantheon"},{"Qiyana"},{"Ryze"},{"Sylas"},{"Syndra"},
    {"Talon"},{"Twisted Fate"},{"Veigar"},{"Viego"},{"Viktor"},{"Vladimir"},{"Xerath"},{"Yasuo"},{"Zed"},{"Ziggs"},
    {"Zoe"},{"Alistar"},{"Bardo"},{"Blitzcrank"},{"Brand"},{"Braum"},{"Galio"},{"Janna"},{"Karma"},{"Leona"},{"Lulu"},
    {"Lux"},{"Maokai"},{"Morgana"},{"Nami"},{"Nautilus"},{"Pyke"},{"Rakan"},{"Rell"},{"Senna"},{"Seraphine"},{"Sett"},
    {"Shaco"},{"Sona"},{"Soraka"},{"Swain"},{"Taric"},{"Thresh"},{"Vel'Koz"},{"Xerath"},{"Yuumi"},{"Zilean"},{"Zyra"},
    {"Aatrox"},{"Camille"},{"Cho'Gath"},{"Darius"},{"Dr. Mundo"},{"Fiora"},{"Gangplank"},{"Garen"},{"Gnar"},{"Gwen"},
    {"Heimerdinger"},{"Illaoi"},{"Irelia"},{"Jax"},{"Jayce"},{"Kayle"},{"Kennen"},{"Kled"},{"Lee Sin"},{"Malphite"},
    {"Mordekaiser"},{"Nasus"},{"Ornn"},{"Quinn"},{"Renekton"},{"Riven"},{"Shen"},{"Singed"},{"Sion"},{"Sylas"},
    {"Tahm Kench"},{"Teemo"},{"Tryndamere"},{"Urgot"},{"Vayne"},{"Wukong"},{"Yasuo"},{"Yone"},{"Yorick"},{"Amumu"},
    {"Diana"},{"Elise"},{"Evelynn"},{"Fiddlesticks"},{"Gragas"},{"Graves"},{"Hecarim"},{"Ivern"},{"Jarvan IV"},
    {"Karthus"},{"Kayn"},{"Kha'Zix"},{"Kindred"},{"Lee Sin"},{"Lillia"},{"Master Yi"},{"Nidalee"},{"Nocturne"},
    {"Nunu e Willump"},{"Olaf"},{"Poppy"},{"Rammus"},{"Rek'Sai"},{"Rengar"},{"Rumble"},{"Sejuani"},{"Shyvana"},
    {"Skarner"},{"Taliyah"},{"Trundle"},{"Udyr"},{"Vi"},{"Volibear"},{"Warwick"},{"Xin Zhao"}, {"Zac"}};
    Champions champions[NUMCHAMPIONS];

    for (int i = 0; i < NUMCHAMPIONS; i ++){
        champions[i].createChampion(nameChampion[i]);
        champions[i].addRoleChampion(ADCARRY);
        champions[i].addClassChampion(MARKSMAN);
        champions[i].ShowChampionInfo();
    }
    FILE * dataFile = NULL;
    if (dataFile = fopen("E:/Clion Projects/untitled/saveChampions.sav", "wb")){
        fwrite(champions, sizeof(champions), 1, dataFile);
        fclose(dataFile);
    }
    else{
        printf("Arquivo nao pode ser aberto");
    }



    return 0;
}

