#include <string>
#include <random>
#include <iostream>
#include "Player.h"

// Implementations file for Player class

// The playerName argument will be provided by the player

Player::Player(std::string playerName)
: m_playerName(playerName), m_playerGuess(" "), m_points(0) { }

Player::Player(const Player& orig) { }

Player::~Player() { }


// makeGuess() method will only allow the player to enter E/e for even or
// O/o for odd, repeat the loop if the player enters anything else.
// If the player tries to be sneaky by entering EO or OE, and ruining
// the other players turn, then ignore
// the second input and use the first input as the answer.

void Player::makeGuess()
{
  while (true)
    {
      std::cout << "Enter E for even O for odd: ";
      char guess;
      std::cin >> guess;
      std::cin.ignore();
      if (guess == 'E' || guess == 'e')
        {
          m_playerGuess = "Cho (even)";
          break;
        }
      else if (guess == 'O' || guess == 'o')
        {
          m_playerGuess = "Han (odd)";
          break;
        }
      else
        {
          std::cout << "Not a valid choice.\n";
        }
    }

}

// This method will be called when the player gets a correct answer

void Player::addPoints(int newPoints)
{
  m_points += newPoints;
}

std::string Player::getName() const
{
  return m_playerName;
}

std::string Player::getGuess() const
{
  return m_playerGuess;
}

int Player::getPoints() const
{
  return m_points;
}
