#include "actor.h"

actor::actor()
{
    type = "actor";
}

actor::~actor()
{
    //dtor
}

unsigned int actor::getHitPoints()
{
    return hit_points;
}

bool actor::inflictDamage(unsigned int damage)
{
    if(damage > hit_points) { damage = hit_points; }
    hit_points -= damage;
    if(hit_points == 0) { return false; }
    return true;
}
