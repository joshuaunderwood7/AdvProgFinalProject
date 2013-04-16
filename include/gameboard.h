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

        bool MoveHeroTo(std::string);
        item* getHero();
        item* getMonster();

        std::string heroRoomInfo();
        bool markVisted();

        bool hasMonster();

        unsigned int getUnvisitedCount();

        void heroCollectTresure();
        bool removeMonster();

        std::vector<std::string>& getAdjacent();

    protected:
        std::map<std::string, location> board;
        std::string heroIn;

    private:


};

#endif // GAMEBOARD_H
