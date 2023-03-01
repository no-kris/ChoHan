#include "Dealer.h"

// Implementations file for Dealer class

// The default values of each dice will be set to 0, but will be discarded

Dealer::Dealer()
: m_dice1Value(0), m_dice2Value(0) { }

Dealer::~Dealer() { }

// This method will use methods from Dice class to roll the 2 dice objects
// and store the values in Dealers dice value attributes

void Dealer::rollDice()
{
  dice1.roll();
  dice2.roll();

  m_dice1Value = dice1.getValue();
  m_dice2Value = dice2.getValue();
}

// This method will add the values from both dice and 
// print Cho or Han depending on if the result is even or odd

std::string Dealer::showChoOrHan()
{
  std::string result;

  int sum{m_dice1Value + m_dice2Value};

  if (sum % 2 == 0)
    result = "Cho (even)";
  else
    result = "Han (odd)";

  return result;
}

int Dealer::getDice1Value() const
{
  return m_dice1Value;
}

int Dealer::getDice2Value() const
{
  return m_dice2Value;
}

