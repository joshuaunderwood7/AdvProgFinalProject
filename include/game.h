#ifndef GAME_H
#define GAME_H

#include "item.h"
#include "gameboard.h"
#include "hero.h"
#include "monster.h"
#include <string>

class game
{
    public:
        game();
        virtual ~game();

        bool takeTurn();
        bool hasWon();

        bool showStatus();

    protected:
        gameboard castle;

        std::string battle(actor*, actor*);

    private:

        void heroCollectTresure();
};

#endif // GAME_H
