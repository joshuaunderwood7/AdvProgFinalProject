#include "include/game.h"
#include <iostream>

int main()
{
    game theBigShow;
    while(theBigShow.takeTurn() && !theBigShow.hasWon())
    { theBigShow.showStatus(); }
    theBigShow.showStatus();
    if(theBigShow.hasWon())
    {
        std::cout << "Congratulations on surviving the game!" << std::endl;
    }
    else
    {
        std::cout << "You lose. Better luck next time." << std::endl;
    }
    return 0;
}
