#ifndef ITEM_H
#define ITEM_H

#include <string>

class item
{
    public:
        //type used to runtime typecheck items in location.h
        std::string type;

        item();
        virtual ~item();

        //PRE: item constructed.
        //POST: returns name.
        std::string getName();

    protected:

        std::string name;

    private:


};

#endif // ITEM_H
