#include <random> // For using a random number engine
#include "Dice.h" 

// Implementations file for the Dice class

// Perform an initial roll when an object of the Dice class is instantiated 

Dice::Dice(int numSides) : m_sides(numSides)
{
  roll();
}

Dice::Dice(const Dice& orig) { }

Dice::~Dice() { }

// The roll method will utilize random number engine and distribution object
// to generate a psuedo-random number between a const value, 1, and 
// the number stored in m_sides attribute

void Dice::roll()
{
  const int MIN{1};

  std::random_device engine;
  std::uniform_int_distribution<int> diceValue(MIN, m_sides);

  m_value = diceValue(engine);
}

int Dice::getSides() const
{
  return m_sides;
}

int Dice::getValue() const
{
  return m_value;
}

