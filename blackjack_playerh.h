#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H
#include <vector>
#include "blackjack_data.h"



class Player
{
private:
    int m_score{};
    std::vector<Card> m_Cards{};
    int m_playerAceCount{};
public:
    Player() = default;


    int getScore() const { return m_score; };
    void addCard(const Card& card);
    void reset();


    friend BlackJackData::Result playBlackJack();
};

#endif // !BLACKJACK_DATA_H