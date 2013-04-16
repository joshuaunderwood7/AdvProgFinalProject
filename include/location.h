#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include "item.h"
//#include "monster.h"

class location
{
    public:

        location();
        location(std::string l_name,
                 std::string l_discription,
                 std::vector<item*> l_items,
                 std::vector<std::string> l_adjacent_locations);

        virtual ~location();

        std::string getName();
        bool hasMonster();
        item* getMonster();
        item* getHero();

        bool addHero(item*);
        bool removeHero();

        bool beenVisited();
        void markVisited();

        std::string getInfo();

        void heroCollectTresure();
        bool removeMonster();

        std::vector<std::string>& getAdjacent();

    protected:

        std::string name;
        std::string discription;

        std::vector<item*> items;
        std::vector<std::string> adjacent_locations;

        bool visited;

    private:




};

#endif // LOCATION_H
