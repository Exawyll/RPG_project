#include <stdio.h>
#include <stdlib.h>
#include "mob.h"

/*- Mob.c : contient les fonctions suivantes :
			- hitMob(Mob* attack, Mob* defence)
			- hitPlayer(Mob* attack, Player* defence)
			- dropLoot(Mob* mob, Player* player)
			- createRandomMob(char name[20], int pointsToAttribut)*/

//define the skill of mobs
Mob* Mob_ctor(char* name, int id, MobRace* race, int lifePoint, int attack, int relativeDEF, int absoluteDEF, int dodge, Equipment* stuff/*Butin*/){
  Mob* p = malloc(sizeof(Mob));
  p->name = name;
  p->id = id;
  p->race = race;
  p->lifePoint = lifePoint;
  p->attack = attack;
  p->relativeDEF = relativeDEF;
  p->absoluteDEF = absoluteDEF;
  p->dodge;
  return p;
}
/*//Show the life of the active mob
void showMobLife(Mob* mobToPrint){
    printf("%s life: %d\n",mobToPrint->name, mobToPrint->lifePoint);
}
//Show characteristics of the mobs
void showMobStats(Mob* mobToPrint){
    printf("id: %d\n", mobToPrint->id);
    showMobLife(mobToPrint);
    printf("attack: %d\n", mobToPrint->attack);
    printf("defense: %d\n", mobToPrint->defence);
}
//deals with the attack action when you hit a mob
void hitMob(Mob* mobAttack, Mob* mobDef){
    mobDef->lifePoint -= mobAttack->attack - mobDef->defence;
    showMobLife(mobDef);
}
//Deals with the defense of the player within a battle
void defPlayer(mob* mobAttack, player* playerDef){
    playerDef->playerMob->lifePoint -= mobAttack->attack - playerDef->playerMob->defence;
    showMobLife(playerDef->playerMob);
    if(playerDef->playerMob->lifePoint <= 0){
        playerDef->life --;
        if(playerDef->life <= 0){
            playerDef->isAlive = 0;
        }
    }
}*/
