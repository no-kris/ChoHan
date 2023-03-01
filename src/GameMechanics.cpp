#include <iostream>
#include <limits>
#include "GameMechanics.h"

namespace GameMechanics
{

  // getRounds() will return the number of rounds, with a limit between 1 - 10.
  // to make sure user does not enter anything that is not a numerical value
  // - check if the std::cin insertion stream encountered any problems
  // - if it did, clear the stream and ignore any other insert, up to \n

  int getRounds()
  {
    while (true)
      {
        std::cout << "How many rounds do you want to play? (1 - 10): ";
        int rounds{0};
        std::cin >> rounds;
        if (std::cin.good() && rounds > 0 && rounds <= 10)
          {
            return rounds;
          }
        else
          {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Try to keep rounds between 1 - 10.\n";
          }
      }
  }

 //===========================================================================//
  
  // play(const std::string& player1Name, const std::string& player2Name)
  // will take in 2 player name references and start the game
  // it will run for the number of rounds the user entered
  // display the round results after the dealer has rolled 
  // the dice and the players have made their guesses
  
  void play(const std::string& player1Name, const std::string& player2Name)
  {
    int rounds{getRounds()};

    Dealer dealer;

    Player player1(player1Name);
    Player player2(player2Name);

    for (int round = 0; round < rounds; ++round)
      {
        std::cout << "====================\n";
        std::cout << "Playing round " << round + 1 << '\n';
        std::cout << "====================\n";

        dealer.rollDice();

        player1.makeGuess();
        player2.makeGuess();

        roundResults(dealer, player1, player2);
      }

    displayWinner(player1, player2);
  }

 //===========================================================================//
  
  // roundResults(Dealer& dealer, Player& player1, Player& player2)
  // will take reference to dealer and players
  // and will use the getter methods from the dealer and player classes
  // to display the results
  
  void roundResults(Dealer& dealer, Player& player1, Player& player2)
  {
    std::cout << "\nThe dealer rolled " << dealer.getDice1Value()
            << " and " << dealer.getDice2Value() << '\n';

    std::cout << "\nResult: " << dealer.showChoOrHan() << '\n';

    checkGuess(player1, dealer);
    checkGuess(player2, dealer);
  }

 //===========================================================================//
  
  // checkGuess(Player& player, Dealer& dealer) will take a reference to
  // a dealer and a player and use the methods from those classes
  // to get a guess from the player and the dealer result
  // if the player guesses right they will receive one point
  
  void checkGuess(Player& player, Dealer& dealer)
  {
    const int ADDITIONAL_POINTS{1};

    std::string guess = player.getGuess();

    std::string choOrHan = dealer.showChoOrHan();

    std::cout << "\nPlayer " << player.getName()
            << " guessed " << player.getGuess() << '\n';

    if (guess == choOrHan)
      {
        player.addPoints(ADDITIONAL_POINTS);
        std::cout << player.getName() << " receives "
                << ADDITIONAL_POINTS << " point.\n";
      }
  }

 //===========================================================================//
  
  // displayWinner(Player& player1, Player& player2) will use the methods 
  // from the player class to output the end results.
  // THen it will display which player won based on how many points they got
  
  void displayWinner(Player& player1, Player& player2)
  {
    std::cout << "==========================\n";
    std::cout << "GAME OVER: THE RESULTS ARE\n";
    std::cout << "==========================\n";

    std::cout << player1.getName() << ": "
            << player1.getPoints() << " points.\n";

    std::cout << player2.getName() << ": "
            << player2.getPoints() << " points.\n";

    if (player1.getPoints() > player2.getPoints())
      std::cout << player1.getName() << " wins!.\n";
    else if (player2.getPoints() > player1.getPoints())
      std::cout << player2.getName() << " wins!.\n";
    else
      std::cout << "It's a draw!.\n";
  }
}



