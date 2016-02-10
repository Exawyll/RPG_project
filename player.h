#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "mob.h"
#include "stuffItems.h"
/*- Player.h : contient l'ensemble des informations nécessaire au joueur humain ou IA
			- identifiant
			- mob
			- nombre de vie (nombre de fois ou le player peut mourrir)
			- or
			- butin*/

typedef struct Player{
    char* name;
    Mob* playerMob;
    int life;
    int gold;
    StuffItem** inventoryStuff;
    //UsableItem** inventoryItem;
}Player;

Player* Player_ctor(char* name, Mob* playerMob,int life, int gold);

/*// Classes are enumerated. WARRIOR = 0; RANGER = 1, etc.
typedef enum ClassEnum  {
  WARRIOR,
  RANGER,
  MAGE,
  DWARF,
} class;*/

#endif // PLAYER_H_INCLUDED
