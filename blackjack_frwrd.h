#ifndef BLACKJACK_FRWRD_H
#define BLACKJACK_FRWRD_H

#include "blackjack_data.h"
#include "blackjack_playerh.h"
#include "blackjack_deck.h"


bool playBlackJackGame();

void playerTurn(Player& player, Deck& deck);
void dealerTurn(Player& dealer, Deck& deck);
BlackJackData::Result playBlackJack();
void testBlackJack();


#endif // !BLACKJACK_FRWRD_H
