#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include "Dealer.h"
#include "Player.h"

namespace GameMechanics
{
    void play (const std::string&, const std::string&);
    void roundResults (Dealer&, Player&, Player&);
    void checkGuess (Player&, Dealer&);
    void displayWinner (Player&, Player&);
}

#endif /* GAMEMECHANICS_H */

