#include <stdio.h>
#include <stdlib.h>
#include "player.h"

/*- Player.c : contient les fonctions suivantes :
			- createPlayer(char name[20], int pointsToAttribut)*/

Player* Player_ctor(char* name, Mob* playerMob, int life, int gold){
    Player* p = malloc(sizeof(Player));
    p->name = name;
    p->playerMob = playerMob;
    p->life = life;
    p->gold = gold;
    return p;
}

void createPlayer(char name, int pointsToAttribut){

}
