/***********************************
 * This is the attacks and combat abilities of the character
 * 
 * Notes for DnD || Pathfinder attacks
 * 
 ***********************************/

#ifndef ATTACK_H
#define ATTACK_H

using namespace std;
#include <string>
#include "ammo.h"


class abilties
{
  protected:
	int numOfAttacks;             //the number of attacks
	int totalAttackBonus;         //the total number of the attack roll
	string abilityName;           //the name of the attack of ability
    int numOfDice;                  //number of dice to be rolled in the spell
    int diceSize;                   //number of sides on the dice rolled
    int additionalDicePerLevel;     //the additional dice added, per level of the character
    int additionalMod;              //any additional modifiers

  public:
    // Getters
    int getNumOfAttacks() { return numOfAttacks;}
    int getTotalAttackBonus() { return totalAttackBonus; }
    string getAbilityName() { return abilityName; }
    int getNumOfDice() { return numOfDice; }
    int getDiceSize() { return diceSize; }
    int getAdditionalDicePerLevel() { return additionalDicePerLevel; }
    int getAdditionalMod() { return additionalMod; }

    // Setters
	void setNumOfAttacks(int numOfAttacks) { this->numOfAttacks = numOfAttacks; }
	void setTotalAttackBonus(int totalAttacksBonus) { this->totalAttackBonus = totalAttackBonus; }
	void setAbilityName(string abilityName) { this->abilityName = abilityName; }
    void setNumOfDice(int numOfDice) { this->numOfDice = numOfDice; }
    void setDiceSize(int diceSize) { this->diceSize = diceSize;}
	void setAdditionalDicePerLevel(int additionalDicePerLevel) { this->additionalDicePerLevel = additionalDicePerLevel; }
	void setAdditionalMod(int additionalMod) { this->additionalMod = additionalMod; }
};

/*********
 * This will contain a list of weapon attacks
 * which the player has access to.
 ********/
class weaponAttacks : private abilties
{
  protected:
    
  public:
    ~weaponAttacks() {}
    weaponAttacks();

    int rollDice();
};

/*********
 * This will contain a list of special ability that can attack
 * which the player has access to.
 ********/
class abilityAttacks : private abilties
{
  protected:
    
  public:
    ~abilityAttacks() {}
    abilityAttacks();

    int rollDice();
};

#endif // ATTACK_H