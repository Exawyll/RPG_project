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

//Creation of list for race
struct node_race
{
    MobRace mobRace;
    struct node_race *p_next;
    struct node_race *p_prev;
} Node_race;

typedef struct race
{
    size_t length;
    struct node_race *p_tail;
    struct node_race *p_head;
} Race;

Race* readFromFile_race();
void writeToFile_race(Race *p_list);
Race *race_find_all(Race *p_list, MobRace mobRace);
Race *race_find(Race *p_list, MobRace mobRace);
size_t race_length(Race *p_list);
Race *race_remove_id(Race *p_list, int position);
Race *race_remove_all(Race *p_list, int mobRace);
Race *race_remove(Race *p_list, MobRace mobRace);
void race_display(Race *p_list);
void race_delete(Race **p_list);
Race *race_insert(Race *p_list, MobRace mobRace, int position);
Race *race_prepend(Race *p_list, MobRace mobRace);
Race *race_append(Race *p_list, MobRace mobRace);
Race *race_new(void);
void printf_struct_race(MobRace* mobRace);

#endif // MOBRACE_H_INCLUDED

