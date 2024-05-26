#include <iostream>

#include "blackjack.h"









int main()
{
    //testBlackJack();

    while (playBlackJackGame())
    {
        switch (playBlackJack())
        {
        case BlackJackData::player_bust:
            std::cout << "\n\033[1;31mYou wen't bust!\nYou lose\033[1;0m\n\n";  // red
            break;
        case BlackJackData::dealer_bust:
            std::cout << "\nThe dealer went bust!\n\033[1;36mYou win!\033[1;0m\n\n";    // cyan
            break;
        case BlackJackData::tie:
            std::cout << "\n\033[1;33mIt's a tie, no one wins!\033[1;0m\n\n";       // yellow
            break;
        case BlackJackData::player_won:
            std::cout << "\n\033[1;36mYou win!\033[1;0m\n\n";
            break;
        case BlackJackData::dealer_won:
            std::cout << "\n\033[1;31mYou lose\033[1;0m\n\n";
            break;
        case BlackJackData::max_results:
            std::cout << "\nError game output!\n\n";
            break;

        default:
            std::cout << "\nError game unknown!\n\n";
            break;
        }

        std::cout << "-------------------------------------------------------\n";
    }


    return 0;
}

