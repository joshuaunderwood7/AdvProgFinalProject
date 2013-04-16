#include "../include/game.h"
#include "../include/actor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdio>

namespace underwood
{
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

  #include <windows.h>

  inline void delay( unsigned long ms )
    {
    Sleep( ms );
    }

#else  /* presume POSIX */

  #include <unistd.h>

  inline void delay( unsigned long ms )
    {
    usleep( ms * 1000 );
    }

#endif
}

game::game()
{
    //ctor
}

game::~game()
{
    //dtor
}

bool game::takeTurn()
{
    srand(time(NULL));
    std::cout << castle.heroRoomInfo();
    castle.markVisted();
    if(castle.hasMonster())
    {
        std::string result = battle((actor*)castle.getHero(), (actor*)castle.getMonster());
        if(result != "HERO") { return false; }
    }

    std::cout << castle.getHero()->getName() << " has " << castle.getUnvisitedCount()
          << " unexplored rooms left to visit." << std::endl << std::endl;

    std::cout << "The adjacent rooms are:" << std::endl;
    std::vector<std::string> &adjacent = castle.getAdjacent();
    for(unsigned int i = 0; i < adjacent.size(); ++i)
    {
        std::cout << "    " << adjacent[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Press <RTN> to change rooms" << std::endl << std::endl;
    std::getchar();

    unsigned int room_move_dice = (rand() % adjacent.size());

    castle.MoveHeroTo(adjacent[room_move_dice]);

    return true;
}

std::string game::battle(actor* _hero, actor* _monster)
{
    srand(time(NULL));
    /*
    Will enters the courtyard with a sword that has a 40% chance of hitting an opponent and
    which can do 5 hits of damage.
    The courtyard is protected by a Gelfing that will take 6 hits to defeat.
    The Gelfing's weapon is a Geff that has a 20% chance of hitting an opponent and it can do 4
    hits of damage.

    Combat begins:

    */
    std::cout << _hero->getName() << " wields a " << _hero->weapon_weilded.getName()
              << " that has a " << _hero->weapon_weilded.getHitPercent() << "% "
              << "chance of hitting an opponent and will can do "
              << _hero->weapon_weilded.getDamage() << " hit points of damage." << std::endl
              << "There is a " << _monster->getName() << " lurking here." << std::endl
              << _monster->getName() << " will take " << _monster->getHitPoints()
              << " hits to defeat." << std::endl
              << "The " << _monster->getName() << "'s weapon is a "
              << _monster->weapon_weilded.getName() << " that has a "
              << _monster->weapon_weilded.getHitPercent() << "% chance of hitting "
              << "an opponent and it can do " << _monster->weapon_weilded.getDamage()
              << " points of damage." << std::endl << std::endl
              << "Combat begins:" << std::endl << std::endl;

    unsigned int percent_dice;
    while(_hero->getHitPoints() != 0 && _monster->getHitPoints() != 0)
    {
        //monster first
        percent_dice = (rand() % 100) + 1;
        if(percent_dice <= _monster->weapon_weilded.getHitPercent())
        {
            _hero->inflictDamage(_monster->weapon_weilded.getDamage());

            std::cout << _monster->getName() << " swings and hits! "
                << _hero->getName() << " loses " << _monster->weapon_weilded.getDamage()
                << " and has " << _hero->getHitPoints() << " remaining." << std::endl
                << std::endl;
        }
        else
        {
            std::cout << _monster->getName() << " swings and misses."
                      << std::endl << std::endl;
        }
        underwood::delay(1000);
        //hero second (if alive)
        if(_hero->getHitPoints() != 0)
        {
            percent_dice = (rand() % 100) + 1;
            if(percent_dice <= _hero->weapon_weilded.getHitPercent())
            {
                _monster->inflictDamage(_hero->weapon_weilded.getDamage());

                std::cout << _hero->getName() << " swings and hits! "
                    << _monster->getName() << " loses " << _hero->weapon_weilded.getDamage()
                    << " and has " << _monster->getHitPoints() << " remaining." << std::endl
                    << std::endl;
            }
            else
            {
                std::cout << _hero->getName() << " swings and misses."
                          << std::endl << std::endl;
            }
        }
        underwood::delay(1000);


        //end of combat loop
    }   //<-- here

    if(_hero->getHitPoints() != 0)
    {
        std::cout << _hero->getName() << " defeats the " << _monster->getName()
                << "! " << std::endl << std::endl;
        //hero collect tresure
        heroCollectTresure();

        //remove moster
        castle.removeMonster();

        return "HERO";
    }
    std::cout << _hero->getName() << " has been slain by the " << _monster->getName()
        << ". " << std::endl << std::endl;
    return "MONSTER";
}

void game::heroCollectTresure()
{
    castle.heroCollectTresure();
}

bool game::hasWon()
{
    if(castle.getUnvisitedCount() != 0) return false;
    return true;
}

bool game::showStatus()
{
    std::cout << castle.getHero()->getName() << " has collected treasures:" << std::endl;
    std::list<tresure>& tresures = dynamic_cast<hero*>(castle.getHero())->getTresure();
    std::list<tresure>::iterator itr;
    unsigned int value = 0;
    for(itr = tresures.begin(); itr != tresures.end(); itr++)
    {
        value += itr->getValue();
        std::cout << "    " << itr->getName() << std::endl;
    }
    std::cout << "Worth a combined value of " << value << std::endl << std::endl;

    std::cout << castle.getHero()->getName() << " has "
              << dynamic_cast<actor*>(castle.getHero())->getHitPoints()
              << " hit points remaining." << std::endl << std::endl;

    return true;
}
