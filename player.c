#include <stdio.h>
#include <stdlib.h>
#include "player.h"

#define ID_PLAYER 1

static void clean (char *chaine);
static void purge_buffer(void);

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

/*static void purge_buffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {}
}

static void clean (char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }

    else
    {
        purge_buffer();
    }
}*/


/*void createPlayer(char* name, int pointsToAttribut){
    int lifePoint = 100;
    int attack = 10;
    int relDEF = 10;
    int absDEF = 10;
    int dodge = 10;
    int userChoice = 0;
    int skillPTS = pointsToAttribut;

    printf("Hi %s, time to set your stats :", name);
    printf("HP: %d\nATT: %d\nRelDEF: %d\nAbsDEF: %d\nESQ: %d\n", lifePoint, attack, relDEF, absDEF, dodge);
    printf("You have %d points to attribute, please select what you want to increase :", pointsToAttribut);
    printf("1: HP\n2: ATT\n3: RelDEF\n4: AbsDEF\n5: ESQ\n");

    //Input of choice to add attributes
    //WARNING :
    scanf("%d", &userChoice);
    switch(userChoice){
        case 1:
            lifePoint += 1;
            skillPTS -=1;
            break;
        case 2:
            attack += 1;
            skillPTS -= 1;
            break;
        case 3:
            relDEF += 1;
            skillPTS -= 1;
            break;
        case 4:
            absDEF += 1;
            skillPTS -= 1;
            break;
        case 5:
            dodge += 1;
            skillPTS -= 1;
            break;
        default:
            break;
    }

    Equipment* start = Equipment_ctor(casque, armor, leggings, boots, sword, shield);
    Mob* mymob = Mob_ctor(name, 1, orc, 20, 10, 20, 10, 1, start);
    Player* myplayer = Player_ctor(name, mymob, 20, 100);
}*/
