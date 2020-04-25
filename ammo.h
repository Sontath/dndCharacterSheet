#ifndef AMMO_H
#define AMMO_H

#include <string>

using namespace std;

class ammo
{
  protected:
    int ammoAmount;
    string name;
    string description;
    int numOfDice;                  //number of dice to be rolled in the spell
    int diceSize;                   //number of sides on the dice rolled
    int additionalDicePerLevel;     //the additional dice added, per level of the character
    int additionalMod;              //any additional modifiers

  public:
    // Getters
    int getAmmoAmount() { return ammoAmount; }
    string getName() { return name; }
    string getDescription() { return description; }
    int getNumOfDice() { return numOfDice; }
    int getDiceSize() { return diceSize; }
    int getAdditionalDicePerLevel() { return additionalDicePerLevel; }
    int getAdditionalMod() { return additionalMod; }

    // Setters
    void setAmmoAmount(int ammoAmount) { this->ammoAmount = ammoAmount;  }
    void setName(string name) { this->name = name;  }
    void setDescription(string description) { this->description = description;  }
    void setNumOfDice(int numOfDice) { this->numOfDice = numOfDice;  }
    void setDiceSize(int diceSize) { this->diceSize = diceSize;  }
};


/*********
 * This will contain a list of the basic ammunition
 * which the player has access to.
 ********/
class basicAmmo : private ammo
{
  protected:

  public:
    ~basicAmmo() {}
    basicAmmo(int ammoAmount, string name, string description, 
              int numOfDice, int diceSize, int additionalDicePerLevel, 
              int additionalMod);
};


/*********
 * This will contain a list of the special ammunition
 * which the player has access to.
 ********/
class specialAmmo : private ammo
{
  protected:

  public:
    ~specialAmmo() {}
	specialAmmo(int ammoAmount, string name, string description, 
                int numOfDice, int diceSize, int additionalDicePerLevel, 
                int additionalMod);
};

#endif // AMMO_H