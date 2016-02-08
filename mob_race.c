#include <stdio.h>
#include <stdlib.h>
#include "mob_race.h"

MobRace* MobRace_ctor(char* name, int R_bonusHP, int R_bonusATT, int R_bonusDEFRel, int R_bonusDEFAbs, int R_bonusESQ){
    MobRace* p = malloc(sizeof(MobRace));
    p->name = name;
    p->R_bonusHP = R_bonusHP;
    p->R_bonusATT = R_bonusATT;
    p->R_bonusDEFRel = R_bonusDEFRel;
    p->R_bonusDEFAbs = R_bonusDEFAbs;
    p->R_bonusESQ = R_bonusESQ;
    return p;
}

