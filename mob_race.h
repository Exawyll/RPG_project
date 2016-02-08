#ifndef MOBRACE_H_INCLUDED
#define MOBRACE_H_INCLUDED


/*- MobRace.h : contient la race du créature (humain, elfe, nain, ...) :
			- nom
			- bonus point vie
			- bonus attaque
			- bonus defense relative
			- bonus defense absolue
			- bonus esquive*/

typedef struct MobRace{
    char* name;
    int R_bonusHP;
    int R_bonusATT;
    int R_bonusDEFRel;
    int R_bonusDEFAbs;
    int R_bonusESQ;
}MobRace;

MobRace* MobRace_ctor(char* name, int R_bonusHP, int R_bonusATT, int R_bonusDEFRel, int R_bonusDEFAbs, int R_bonusESQ);

#endif // MOBRACE_H_INCLUDED

