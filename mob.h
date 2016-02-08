#ifndef MOB_H_INCLUDED
#define MOB_H_INCLUDED

#include "mob_race.h"
#include "equipment.h"

/*- Mob.h : contient l'ensemble des informations li�e � une cr�ature :
			- identifiant
			- nom
			- mobrace
			- point de vie
			- attaque
			- defense relative (% de reduction de d�gat)
			- defense absolue (reduction de d�gat fixe)
			- esquive
			- equipement
			- butin (comprend une liste de usableitem ET/OU de stuffitem)*/

typedef struct Mob{
    char* name;
    int id;
    MobRace* race;
    int lifePoint;
    int attack;
    int relativeDEF;
    int absoluteDEF;
    int dodge;
    Equipment* stuff;
    //butin
}Mob;

Mob* Mob_ctor(char* name, int id, MobRace* race, int lifePoint, int attack, int relativeDEF, int absoluteDEF, int dodge, Equipment* stuff/*Butin*/);

#endif // MOB_H_INCLUDED
