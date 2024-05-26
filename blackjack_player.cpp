#include <vector>
#include <cassert>

#include "blackjack_data.h"
#include "blackjack_playerh.h"

void Player::addCard(const Card& card)
{
	static bool cardRepeat{};


	cardRepeat = false;
	for ([[maybe_unused]] const Card& playerCard : m_Cards)
	{
		if ((playerCard.rank == card.rank) && (playerCard.suit == card.suit))
			cardRepeat = true;
	}

	assert(!cardRepeat && "Player::addCard encountered repeat card");

	m_Cards.push_back(card);
	m_score += BlackJackData::ranksScore[card.rank];

	if (card.rank == BlackJackData::rank_ace) ++m_playerAceCount;

	if (m_score > Settings::targetVal && m_playerAceCount>0)
	{
		m_score -= 10;
		--m_playerAceCount;
	}
}



void Player::reset()
{
	m_Cards.resize(0);
	m_Cards.shrink_to_fit();
	m_score = 0;
}


