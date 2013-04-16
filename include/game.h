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


        //PRE:game has been constructed.
        //POST: prints to standard output.
        //  The game shows room information.
        //  The game initiates combat.
        //  returns true if hero is alive. false otherwise
        bool takeTurn();

        //PRE:game has been constructed.
        //POST: returns true if hero is alive. false otherwise.
        bool hasWon();

        //PRE:game has been constructed.
        //POST: prints to standard output.
        //  game shows hero's status: hit_points and collected tresure.
        bool showStatus();

    protected:
        gameboard castle;

        //PRE: pass constructed (hero*, monster*).
        //POST: prints to standard output.
        //  game plays automated combat, and displays steps.
        //  returns "HERO" if the hero wins. returns "MONSTER" otherwise
        std::string battle(actor*, actor*);

    private:

        //PRE: location has hero and monster.
        //POST: calls to gameboard->location to transfer tresure from
        //      monster to hero.
        void heroCollectTresure();
};

#endif // GAME_H
