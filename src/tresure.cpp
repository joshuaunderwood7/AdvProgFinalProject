#include "../include/tresure.h"

tresure::tresure(unsigned int amount) : tresure_value(amount)
{
    name = "a stack of gold coins";
    type = "tresure";
}

tresure::tresure()
{
    tresure_value = 0;
    name = "an empty sack";
    type = "tresure";
}

tresure::~tresure()
{
    //dtor
}

unsigned int tresure::getValue()
{
    return tresure_value;
}
