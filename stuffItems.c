#include <stdio.h>
#include <stdlib.h>

#include "stuffItems.h"
/*- StuffItem.c : contient les fonctions suivantes :
			- eqpStuffItem(StuffItem* item, Mob* mob)
			- unEqpStuffItem(StuffItem* item, Mob* mob)
			- sellStuffItem(StuffItem* item, Player* player)*/

StuffItem* stuffItem_ctor(char* name, int price, int type, int I_bonusHP, int I_bonusATT, int I_bonusDEFRel, int I_bonusDEFAbs){
    StuffItem* p = malloc(sizeof(StuffItem));
    p->name = name;
    p->price = price;
    p->type = type;
    p->I_bonusHP = I_bonusHP;
    p->I_bonusATT = I_bonusATT;
    p->I_bonusDEFRel = I_bonusDEFRel;
    p->I_bonusDEFAbs = I_bonusDEFAbs;
    return p;
}



/*void eqpStuffItem(StuffItem* item, Mob* mob){
}

void unEqpStuffItem(StuffItem* item, Mob* mob){
}

void sellStuffItem(StuffItem* item, Player* player){
}*/
