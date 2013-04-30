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

        //PRE: location constructed.
        //POST: returns name.
        std::string getName();
        //PRE: location constructed.
        //POST: returns true if monster in items.
        bool hasMonster();
        //PRE: location constructed.
        //POST: returns monster first monster in items.
        item* getMonster();
        //PRE: hero in items.
        //POST: returns hero.
        item* getHero();

        //PRE: hero constructed.
        //POST: returns hero in items.
        bool addHero(item*);
        //PRE: location constructed.
        //POST: removes hero from items.
        bool removeHero();

        //PRE: location constructed.
        //POST: returns visited.
        bool beenVisited();
        //PRE: location constructed.
        //POST: sets visited to true.
        void markVisited();

        //PRE: location constructed.
        //POST: returns location name and description as string.
        std::string getInfo();

        //PRE: location items contains monster and hero.
        //POST: monster.tresure added to hero.tresure_collected.
        void heroCollectTresure();
        //PRE: monster in location items.
        //POST: removes monster from location items.
        bool removeMonster();

        //PRE: location constructed.
        //POST: returns adjacent_locations, (names of adjacent locations).
        std::vector<std::string>& getAdjacent();

    protected:

        std::string name;
        std::string discription;

        std::vector<item*> items;
        std::vector<std::string> adjacent_locations;

        bool visited;

//        static bool deleteAll( item* theElement ) { delete theElement; return true; }

    private:
};

#endif // LOCATION_H
