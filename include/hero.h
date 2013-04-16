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

        bool addTresure(tresure);
        std::list<tresure>& getTresure();

    protected:
    private:
};

#endif // HERO_H
