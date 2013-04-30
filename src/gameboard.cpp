#include "../include/gameboard.h"
#include "../include/location.h"
#include "../include/item.h"
#include "../include/monster.h"
#include "../include/hero.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

/*location(std::string &l_name,
                 std::string &l_discription,
                 std::vector<item> &l_items,
                 std::vector<std::string> &l_adjacent_locations)
                 */
gameboard::gameboard()
{
    srand(time(NULL)); // moved here to prevent exact copied of monsters in
                       // each room.
    
    std::vector<std::string> adjacent_locations;
    std::vector<item*> l_items;

    adjacent_locations.push_back("Courtyard");
    l_items.push_back(new monster());
    board.insert(std::pair<std::string,location>(
                  "Art Room",
                  location("Art Room",
                           "There are lovely pictures on the walls, and a monster.",
                           l_items,
                           adjacent_locations)));
    adjacent_locations.clear();
    l_items.clear();

    adjacent_locations.push_back("Art Room");
    adjacent_locations.push_back("Great Hall");
    adjacent_locations.push_back("Guard Room");
    l_items.push_back(new monster());
    board.insert(std::pair<std::string,location>(
                  "Courtyard",
                  location("Courtyard",
                           "A beautiful statue of a lady stands in the center of this courtyard, and a monster.",
                           l_items,
                           adjacent_locations)));
    adjacent_locations.clear();
    l_items.clear();

    adjacent_locations.push_back("Courtyard");
    adjacent_locations.push_back("Dungeon");
    l_items.push_back(new monster());
    board.insert(std::pair<std::string,location>(
                  "Great Hall",
                  location("Great Hall",
                           "Wonderful hall with tapestries and a monster.",
                           l_items,
                           adjacent_locations)));
    adjacent_locations.clear();
    l_items.clear();

    adjacent_locations.push_back("Great Hall");
    l_items.push_back(new monster());
    board.insert(std::pair<std::string,location>(
                  "Dungeon",
                  location("Dungeon",
                           "The shackles and torture devices line the walls of the dungeon, and among them, a monster.",
                           l_items,
                           adjacent_locations)));
    adjacent_locations.clear();
    l_items.clear();

    adjacent_locations.push_back("Courtyard");
    l_items.push_back(new monster());
    l_items.push_back(new hero());
    board.insert(std::pair<std::string,location>(
                  "Guard Room",
                  location("Guard Room",
                           "A relatively empty room. Clearly this room has been cleared of everything except a monster.",
                           l_items,
                           adjacent_locations)));
    adjacent_locations.clear();
    l_items.clear();

    heroIn = "Guard Room";

}

gameboard::~gameboard()
{
    //dtor
}

bool gameboard::MoveHeroTo(std::string new_location)
{
    board[new_location].addHero(getHero());
    board[heroIn].removeHero();
    heroIn = new_location;
    return true;
}

item* gameboard::getHero()
{
    return board[heroIn].getHero();
}

item* gameboard::getMonster()
{
    return board[heroIn].getMonster();
}

std::string gameboard::heroRoomInfo()
{
    return getHero()->getName() + " enters The " +
           board[heroIn].getName() + "\n" + board[heroIn].getInfo();
}

bool gameboard::markVisted()
{
    board[heroIn].markVisited();
    return true;
}

bool gameboard::hasMonster()
{
    return board[heroIn].hasMonster();
}

unsigned int gameboard::getUnvisitedCount()
{
    unsigned int count = 0;
    std::map<std::string, location>::iterator loc;
    for(loc = board.begin(); loc != board.end(); loc++)
    {
        if(!loc->second.beenVisited()) { count++; }
    }
    return count;
}

void gameboard::heroCollectTresure()
{
    board[heroIn].heroCollectTresure();
}

bool gameboard::removeMonster()
{
    return board[heroIn].removeMonster();
}

std::vector<std::string>& gameboard::getAdjacent()
{
    return board[heroIn].getAdjacent();
}
