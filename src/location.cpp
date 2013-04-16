#include "../include/location.h"
#include "../include/tresure.h"
#include "../include/monster.h"
#include "../include/hero.h"

location::location()
{
    //ctor
}

location::location(std::string l_name,
                 std::string l_discription,
                 std::vector<item*> l_items,
                 std::vector<std::string> l_adjacent_locations) :
                 name(l_name), discription(l_discription),
                 items(l_items), adjacent_locations(l_adjacent_locations)
{
    visited = false;
}

location::~location()
{
    /*
    std::vector<item*>::iterator iter;
    for(iter = items.begin(); iter != items.end(); iter++)
    {
        delete *iter;
    }
    */
}

std::string location::getName() {return name;}

bool location::hasMonster()
{
    for(unsigned int i = 0; i < items.size(); ++i)
    {
        if(items[i]->type == "monster") return true;
    }
    return false;
}

item* location::getMonster()
{
    for(unsigned int i = 0; i < items.size(); ++i)
    {
        if(items[i]->type == "monster") return items[i];
    }
    return NULL;
}

item* location::getHero()
{
    for(unsigned int i = 0; i < items.size(); ++i)
    {
        if(items[i]->type == "hero") return items[i];
    }
    return NULL;
}

bool location::beenVisited()
{
    return visited;
}

void location::markVisited()
{
    visited = true;
}

bool location::addHero(item* hero_to_add)
{
    items.push_back(hero_to_add);
    return true;
}

bool location::removeHero()
{
    for(unsigned int i = 0; i < items.size(); ++i)
    {
        if(items[i]->type == "hero")
        {
            items[i] = items[items.size()-1];
            items.pop_back();
        }

    }
    return true;
}

std::string location::getInfo()
{
    std::string info = discription + "\n";
    if(!hasMonster())
    {
        info += "But this monster is dead.\n";
    }
    return info;
}

void location::heroCollectTresure()
{
    tresure loot;
    for(unsigned int i = 0; i < items.size(); ++i)
    {
        if(items[i]->type == "monster")
        {
            loot = dynamic_cast<monster*>(items[i])->getTresure();
        }
    }
    for(unsigned int i = 0; i < items.size(); ++i)
    {
        if(items[i]->type == "hero")
        {
            dynamic_cast<hero*>(items[i])->addTresure(loot);
        }
    }
}

bool location::removeMonster()
{
    for(unsigned int i = 0; i < items.size(); ++i)
    {
        if(items[i]->type == "monster")
        {
            items[i] = items[items.size()-1];
            items.pop_back();
            return true;
        }

    }
    return false;
}

std::vector<std::string>& location::getAdjacent()
{
    return adjacent_locations;
}
