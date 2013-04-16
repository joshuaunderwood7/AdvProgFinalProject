#include "../include/weapon.h"
#include <stdlib.h>
#include <time.h>

weapon::weapon(typeOf weaponType)
{
    type = "weapon";
    srand(time(NULL));
    int rweapon = rand() % 3;
    switch (weaponType)
    {
        case HERO:
            if(rweapon == 0)
            {
                name = "Sword";
                hit_value = 5;
                hit_probablity = 40;
            }
            else if (rweapon == 1)
            {
                name = "Axe";
                hit_value = 4;
                hit_probablity = 50;
            }
            else
            {
                name = "Spear";
                hit_value = 3;
                hit_probablity = 60;
            }
        break;
        case MONSTER:
            if(rweapon == 0)
            {
                name = "Troth";
                hit_value = 5;
                hit_probablity = 50;
            }
            else if (rweapon == 1)
            {
                name = "Geff";
                hit_value = 4;
                hit_probablity = 20;
            }
            else
            {
                name = "Beff";
                hit_value = 3;
                hit_probablity = 35;
            }
        break;
        default:
        break;
    }
}

weapon::weapon()
{
    name = "no weapon";
    hit_value = 1;
    hit_probablity = 10;
}

weapon::~weapon()
{
    //dtor
}


unsigned int weapon::getHitPercent()
{
    return hit_probablity;
}

unsigned int weapon::getDamage()
{
    return hit_value;
}
