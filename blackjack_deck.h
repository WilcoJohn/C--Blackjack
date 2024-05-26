#include <array>
#include "blackjack_data.h"



#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H
class Deck
{
private:
    std::array<Card, BlackJackData::amtCards> m_Deck{};
    std::size_t m_deckIdx{};
public:
    Deck();
    
    const Card& dealCard();
    void shuffle();
    void reset();
};
#endif // !BLACKJACK_DATA_H