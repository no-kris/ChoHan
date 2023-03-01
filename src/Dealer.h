#ifndef DEALER_H
#define DEALER_H

#include <string>
#include "Dice.h" // Use the attributes and methods from Dice class

// specifications file for Dealer class

class Dealer
{
public:
  // Constructors and destructor
  Dealer ();
  virtual ~Dealer ();
  // Methods
  void rollDice ();
  std::string showChoOrHan ();
  int getDice1Value () const;
  int getDice2Value () const;
private:
  // "has-a" relationship with Dice class to create 2 private attributes
  // to store a value for each dice object 
  Dice dice1 {};
  Dice dice2 {};
  int m_dice1Value {};
  int m_dice2Value {};
};

#endif /* DEALER_H */

