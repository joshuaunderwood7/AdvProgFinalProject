#ifndef ITEM_H
#define ITEM_H

#include <string>

class item
{
    public:
        std::string type;

        item();
        virtual ~item();

        std::string getName();

    protected:

        std::string name;

    private:


};

#endif // ITEM_H
