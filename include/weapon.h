#ifndef WEAPON_H
#define WEAPON_H

#include "prop.h"

enum typeOf
{
    HERO,
    MONSTER
};

class weapon : public prop
{
    public:

        weapon();
        weapon(typeOf weaponType);
        virtual ~weapon();

        //PRE: weapon constructed.
        //POST: returns hit_probability.
        unsigned int getHitPercent();
        //PRE: weapon constructed.
        //POST: returns hit_value.
        unsigned int getDamage();

    protected:
        unsigned int hit_value;
        unsigned int hit_probablity;

    private:
};

#endif // WEAPON_H
