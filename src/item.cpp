#include "../include/item.h"

item::item()
{
    type = "item";
}

item::~item()
{
    //dtor
}

std::string item::getName() {return name;}
