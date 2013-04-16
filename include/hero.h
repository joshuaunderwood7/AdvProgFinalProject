#ifndef HERO_H
#define HERO_H

#include "actor.h"
#include "tresure.h"
#include <list>

class hero : public actor
{
    public:
        std::list<tresure> tresure_collected;
        hero();
        virtual ~hero();

        //PRE: hero constructed.
        //POST: adds input tresure to tresure_collected
        bool addTresure(tresure);
        //PRE: hero constructed.
        //POST: returns tresure_collected.
        std::list<tresure>& getTresure();

    protected:
    private:
};

#endif // HERO_H
