#include <iostream>
#include <limits>
#include "blackjack_frwrd.h"



bool playBlackJackGame()
{
    while (true)
    {
        std::cout << "Would you like to play black jack (y) or (n):";


        char input{};
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice, try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        switch (input)
        {
        case 'y':
        case 'Y': return true;
        case 'n':
        case 'N': return false;
        default:
            std::cout << "Invalid input. Try again.\n";
            break;
        }
    }
}








void playerTurn(Player& player, Deck& deck)
{
    char playerChoice{};
    while (player.getScore() <= Settings::targetVal)
    {
        std::cout << "(h) to hit, or (s) to stand: ";
        std::cin >> playerChoice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice, try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        switch (playerChoice)
        {
        case 'S':
        case 's': return;
        case 'H':
        case 'h': break;
        default:
            std::cout << "Invalid choice, try again.\n";
            continue;
        }

        Card card{ deck.dealCard() };
        player.addCard(card);
        std::cout << "You were dealt a " << card << ". You now have: \033[1;32m" << player.getScore() << "\033[1;0m\n";
    }
}


void dealerTurn(Player& dealer, Deck& deck,Player& player)
{


    while (dealer.getScore() < Settings::dealerStopAt)
    {
        Card card{ deck.dealCard() };
        dealer.addCard(card);

        std::cout << "The dealer flips a " << card << ". They now have: \033[1;32m" << dealer.getScore() << "\033[1;0m\n";
        if ((dealer.getScore() > Settings::targetVal) || (dealer.getScore() > player.getScore())) return;
    }


}


BlackJackData::Result playBlackJack()
{
    Player player{};
    Player dealer{};
    Deck deck{};

    deck.shuffle();
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());

    std::cout << "The dealer is showing " << dealer.m_Cards[0] << " (\033[1;32m" << dealer.getScore() << "\033[1;0m)\n";

    std::cout << "\nYou are showing ";
    for (const auto& val : player.m_Cards)
        std::cout << val << ' ';
    std::cout << "(\033[1;32m" << player.getScore() << "\033[1;0m) \n\n";

    playerTurn(player, deck);

    if (player.getScore() > Settings::targetVal) return BlackJackData::player_bust;

    std::cout << "\n";
    dealerTurn(dealer, deck, player);
    if (dealer.getScore() > Settings::targetVal) return BlackJackData::dealer_bust;

    if (dealer.getScore() == player.getScore()) return BlackJackData::tie;

    return ((dealer.getScore() > player.getScore()) ? BlackJackData::dealer_won : BlackJackData::player_won);
}



void testBlackJack()
{

    // test name space acces
    std::cout << "In Jackblack try to get " << Settings::targetVal << '\n';

    // test card creation
    Card card1{ };
    {
        using enum BlackJackData::Ranks;
        using enum BlackJackData::Suits;
        card1 = Card{ rank_ace, diamond };
    }
    std::cout << "Using cards such as " << card1 << '\n';

    // test deck utility
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << " or \n";
    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';
    deck.reset();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';
    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';


    Player player{};

    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());

    //player.addCard(card1);
    //player.addCard(card1);    // test for repeat cards

    deck.shuffle();

    bool playGame{ playBlackJackGame() };

    if (playGame)
        playBlackJack();
}
