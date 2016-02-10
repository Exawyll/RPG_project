#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "equipment.h"

#define POINTS_ATTRIBUTE 10

//- main.c : lance le jeu
void DisplayStats (Player* Target);
static void clean (char *chaine);
static void purge_buffer(void);

int main(int argc, char *argv[])
{
    createMobRace();
    /*createStuff();
    char* name;

    printf("Please give a name for your character : ");
    fgets(name, sizeof(name), stdin);

    clean(name);*/

    //createPlayer(name, POINTS_ATTRIBUTE);

    //DisplayStats(myplayer);

    return 0;
}

void DisplayStats (Player* Target) {
    printf("Name: %s\nHealth: %d\nGold: %d\nRace: %s\n", Target->name, Target->life, Target->gold, Target->playerMob->race->name);
}

static void purge_buffer(void)
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
}
