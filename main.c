#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "equipment.h"
#include "stuffItems.h"

//- main.c : lance le jeu
void DisplayStats (Player* Target);

int main(int argc, char *argv[])
{
    StuffItem* casque = stuffItem_ctor("beret", 100, 0, 10, 2, 10, 3);
    StuffItem* armor = stuffItem_ctor("plate", 100, 1, 10, 2, 10, 3);
    StuffItem* leggings = stuffItem_ctor("cuir", 100, 2, 10, 2, 10, 3);
    StuffItem* boots = stuffItem_ctor("sandales", 100, 1, 10, 2, 10, 3);
    StuffItem* sword = stuffItem_ctor("katana", 100, 1, 10, 2, 10, 3);
    StuffItem* shield = stuffItem_ctor("bouclier", 100, 1, 10, 2, 10, 3);

    MobRace* gobelin = MobRace_ctor("Gobelin", 0, 1, 10, 1, 0);
    MobRace* human = MobRace_ctor("Human", 10, 2, 10, 2, 2);
    MobRace* elf = MobRace_ctor("Elf", 5, 1, 20, 1, 3);
    MobRace* orc = MobRace_ctor("Orc", 12, 3, 5, 4, 0);

    Equipment* start = Equipment_ctor(casque, armor, leggings, boots, sword, shield);
    Mob* mymob = Mob_ctor("Exaw", 1, orc, 20, 10, 20, 10, 1, start);
    Player* myplayer = Player_ctor("Exaw", mymob, 20, 100);

    /*mob* mob1 = mob_ctor("mob1",50,1,0,10);

    mob* mob2 = mob_ctor("mob2",51,1,0,10);

    mob* mob3 = mob_ctor("mob3",52,1,0,10);

    mob* mob4 = mob_ctor("mob4",53,1,0,10);

    mob* mob5 = mob_ctor("mob5",54,1,0,10);*/
    DisplayStats(myplayer);

    return 0;
}

void DisplayStats (Player* Target) {
    printf("Name: %s\nHealth: %d\nGold: %d\nRace: %s\n", Target->name, Target->life, Target->gold, Target->playerMob->race->name);
}
