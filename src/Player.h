#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// Specifications file for Player class

class Player
{
public:
  // Constructors and destructor
  Player (std::string);
  Player (const Player& orig);
  virtual ~Player ();
  // Methods
  void makeGuess ();
  void addPoints (int);
  std::string getName () const;
  std::string getGuess () const;
  int getPoints () const;
private:
  std::string m_playerName;
  std::string m_playerGuess;
  int m_points {};
};

#endif /* PLAYER_H */

