#include <iostream>
#include <array>
#include <cassert>


#ifndef BLACKJACK_DATA_H
#define BLACKJACK_DATA_H


namespace BlackJackData
{

    inline constexpr int amtCards{ 52 };

    enum Result
    {
        player_bust,
        dealer_bust,
        tie,
        player_won,
        dealer_won,
        max_results
    };

    enum Suits
    {
        diamond,
        heart,
        clubs,
        spade,
        max_suits,

    };

    enum Ranks
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        max_ranks,
    };

    constexpr std::array allSuits{ diamond,heart,clubs,spade };
    constexpr std::array allRanks{ rank_ace,rank_2,rank_3,rank_4,rank_5,rank_6,rank_7,rank_8,rank_9,rank_10,rank_jack,rank_queen,rank_king };
    constexpr std::array ranksScore{ 11,2,3,4,5,6,7,8,9,10,10,10,10 };
    constexpr std::array ranksDisp{ 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
    constexpr std::array suitsDisp{ 'D','H','C','S' };


    static_assert(max_ranks == std::size(ranksScore));
    static_assert(max_ranks == std::size(allRanks));
    static_assert(max_suits == std::size(allSuits));
    static_assert(max_suits == std::size(suitsDisp));
}
#endif // !BLACKJACK_DATA_H



#ifndef BLACKJACK_SETTINGSS_H
#define BLACKJACK_SETTINGSS_H

namespace Settings
{
    inline constexpr int targetVal{ 21 };
    inline constexpr int dealerStopAt{ 17 };

}

#endif // !BLACKJACK_DATA_H


#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

struct Card
{
    BlackJackData::Ranks rank{};
    BlackJackData::Suits suit{};


    friend std::ostream& operator<<(std::ostream& out, Card card)
    {
        return out << BlackJackData::ranksDisp[card.rank] << BlackJackData::suitsDisp[card.suit];
    }
};

#endif // !BLACKJACK_DATA_H


