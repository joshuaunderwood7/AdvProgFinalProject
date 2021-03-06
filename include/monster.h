#ifndef MONSTER_H
#define MONSTER_H

#include "actor.h"
#include "tresure.h"

class monster : public actor
{
    public:
        tresure tresure_held;
        monster();
        virtual ~monster();

        //PRE: monster constructed.
        //POST: returns tresure_held.
        tresure getTresure();

    protected:
    private:
};

#endif // MONSTER_H
