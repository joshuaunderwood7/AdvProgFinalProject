#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <string>
#include <map>
#include <vector>
#include "location.h"
#include "hero.h"

class gameboard
{
    public:
        gameboard();
        virtual ~gameboard();

        //PRE: gameboard constructed,
        //     location exists with location.name == input string.
        //POST: hero is moved to new room and removed from privous location.
        //NOTE: segfault upon EXIT of invalid room. check strings in location
        //      construction.
        bool MoveHeroTo(std::string);

        //PRE: hero in valid location.
        //POST: returns pointer to hero.
        item* getHero();
        //PRE: hero in valid location.
        //POST: returns pointer to monster at hero's location.
        item* getMonster();

        //PRE: hero in valid location.
        //POST: gets room name, and description of room hero is in.
        std::string heroRoomInfo();

        //PRE: hero in valid location.
        //POST: location hero is in is marked as visited.
        bool markVisted();

        //PRE: hero in valid location.
        //POST: returns true if a monster exists in hero location.
        bool hasMonster();

        //PRE: gameboard constructed.
        //POST: returns number of rooms the hero has not entered.
        unsigned int getUnvisitedCount();

        //PRE: location has hero and monster.
        //POST: calls to location to transfer tresure from
        //      monster to hero.
        void heroCollectTresure();

        //PRE: hero in valid location.
        //POST: removes monster from hero location.
        bool removeMonster();

        //PRE: hero in valid location.
        //POST: returns vector<string> of locations adjacent to hero location.
        std::vector<std::string>& getAdjacent();

    protected:
        std::map<std::string, location> board;
        std::string heroIn;

    private:
};

#endif // GAMEBOARD_H
