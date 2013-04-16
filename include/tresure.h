#ifndef TRESURE_H
#define TRESURE_H

#include "prop.h"


class tresure : public prop
{
    public:

        tresure();
        tresure(unsigned int amount);
        virtual ~tresure();

        unsigned int getValue();

    protected:

        unsigned int tresure_value;

    private:
};

#endif // TRESURE_H
