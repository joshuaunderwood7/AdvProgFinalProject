#include "hero.h"
#include "weapon.h"

hero::hero()
{
    name = "Adventurer";
    hit_points = 50;
    weapon_weilded = weapon(HERO);
    type = "hero";
}

hero::~hero()
{
    //dtor
}

bool hero::addTresure(tresure collected)
{
    tresure_collected.push_front(collected);
    return true;
}

std::list<tresure>& hero::getTresure()
{
    return tresure_collected;
}
