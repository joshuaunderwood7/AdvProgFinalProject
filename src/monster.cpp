#include "../include/monster.h"
#include "../include/weapon.h"
#include "../include/tresure.h"
#include <stdlib.h>
#include <time.h>

monster::monster()
{
//    srand(time(NULL)); //moved to gameboard.cpp
    int rtype = rand() % 3;
    switch (rtype)
    {
        case 0:
            name = "Troll";
            hit_points = 13;
        break;
        case 1:
            name = "Gelfling";
            hit_points = 6;
        break;
        case 2:
            name = "Belf";
            hit_points = 7;
        break;
    }
    weapon_weilded = weapon(MONSTER);
    tresure_held = tresure(100);
    type = "monster";
}

monster::~monster()
{
    //dtor
}

tresure monster::getTresure()
{
    return tresure_held;
}
