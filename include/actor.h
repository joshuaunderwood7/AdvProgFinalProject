#ifndef ACTOR_H
#define ACTOR_H

#include "item.h"
#include "weapon.h"

class actor : public item
{
    public:
        unsigned int hit_points;
        weapon weapon_weilded;
        actor();
        virtual ~actor();

        //PRE:(none)
        //POST: returns hit_points
        unsigned int getHitPoints();

        //PRE:unsigned input "damage"
        //POST: reduces hit points by damage, if damage greater than hit_points
        //hit_points is reduced to 0.
        //returns false if hit_points is equal to 0.
        //returns true otherwise.
        bool inflictDamage(unsigned int damage);

    protected:
    private:
};

#endif // ACTOR_H
