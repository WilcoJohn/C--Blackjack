#include <algorithm>
#include <cassert>

#include "blackjack_data.h"
#include "blackjack_deck.h"
#include "random.h"

Deck::Deck()
{
	m_deckIdx = 0;
	for (const auto& suit: BlackJackData::allSuits)
		for (const auto& rank : BlackJackData::allRanks)
			m_Deck[m_deckIdx++] = Card{ rank, suit };
	m_deckIdx = 0;
}


void Deck::shuffle()
{
	m_deckIdx = 0;
	std::shuffle(std::begin(m_Deck), std::end(m_Deck),Random::mt);
}

const Card& Deck::dealCard()
{
	assert(m_deckIdx < BlackJackData::amtCards && "Deck index out of bounds");
	return m_Deck[m_deckIdx++];
}



void Deck::reset()
{
	m_deckIdx = 0;
	for (const auto& suit: BlackJackData::allSuits)
		for (const auto& rank : BlackJackData::allRanks)
			m_Deck[m_deckIdx++] = Card{ rank, suit };
	m_deckIdx = 0;
}