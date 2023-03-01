#include <iostream>
#include "Dealer.h"
#include "Player.h"
#include "GameMechanics.h"

int main()
{
  std::cout << "===================\n";
  std::cout << "WELCOME TO CHO HAN\n";
  std::cout << "===================\n";
  std::cout << "Rules: Two players will take turns guessing even (cho)\n"
          << "or odd (han). Dealer will roll 2 dice and add the results.\n"
          << "If the player guesses right they will receive 1 point.\n";
  std::cout << "===================\n";
  std::cout << "LET'S PLAY!\n";
  std::cout << "===================\n";

  std::cout << "Enter player 1 name: ";
  std::string player1Name;
  std::getline(std::cin >> std::ws, player1Name);

  std::cout << "Enter player 2 name: ";
  std::string player2Name;
  std::getline(std::cin >> std::ws, player2Name);

  GameMechanics::play(player1Name, player2Name);

  return 0;
}


