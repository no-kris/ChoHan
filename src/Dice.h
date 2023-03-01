#ifndef DICE_H
#define DICE_H

// Specification file for the Dice class
// Dice class will be used for rolling the dice and getting the value

class Dice
{
public:
  // Constructors and destructor
  Dice (int = 6);
  Dice (const Dice& orig);
  virtual ~Dice ();
  // Methods
  void roll ();
  int getSides () const;
  int getValue () const;
private:
  int m_sides {};
  int m_value {};
};

#endif /* DICE_H */

