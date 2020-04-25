/**********************************************************
* Spells
*
* Subtypes: rolledSpells, infoSpells
*
* Summary: Spells are going to contain any and all information
* for the Dungeon and Dragons / Pathfinder spells. This information should be
* stored, and should be able to be displayed to the user in
* and easy fashion.
**********************************************************
* Casting Spells Guide: 
* First: the player must be of the appropriate character's level.
* Second: the player must be able to cast the appropriate spell's level.
* Third: the player must have an available spell slot of that spell's level.
* Fourth: the player must have the available material components to cast the spell.
* Once these four conditions are met, the player may cast the spell.
**********************************************************/

#ifndef SPELLBOOK_H
#define SPELLBOOK_H

using namespace std;
#include <string>

enum School
{
    abjuration, //spells that protect, create barriers, ward off enemies, or warn of dangers
    conjuration, //spells that create life, creates objects, and brings manifestations
    divination, //spells that reveal truths and predicts realities
    enchantment, //spells that infleunce and control other things
    evocation, //spells that evoke energy and elements
    illusion, //spells that alter one's perception of reality
    necromancy, //spells that invoke the effects life and death
    transmutation, //spells that change the properties of things and creatures
    universal, //spells that cannot be contained to the other categories or spells that combine more than one category
};



/*********
 * This is a base class for spells that will be used for the
 * polymorphism of the spell classes
 ********/
class Spell
{
  protected:
    int minLevel;       //minimum spell's level required to cast spell
    School school;      //the magical school of the spell
    string castTime;    //type of action needed to cast spell, and possible rounds
    string components;  //material or otherwise components
    string range;       //the maximum and if specified, minimum range needed
    string target;      //what type of targets the spell can affect
    string duration;    //duration the spell continues
    string savingThrow; //the target's chance to save against the spell
    string resistance;  //the target's chance to resist the spell through the spell resistance
    string description; //a description of the spell's effects
  public:
    ~Spell() {}
    int getMinLevel() { return minLevel; }
    virtual bool cast(int desiredLevel) = 0; // display information about the spell to the user.
};

/*********
 * This will contain any spells that require a roll of the dice
 * to be made in order for the spell to be cast.
 ********/
class RolledSpell : private Spell
{
  protected:
    int numOfDice;                  //number of dice to be rolled in the spell
    int diceSize;                   //number of sides on the dice rolled
    int additionalDicePerLevel;     //the additional dice added, per level of the character
    int additionalMod;              //any additional modifiers
    
  public:
    ~RolledSpell() {}
    RolledSpell(int minLevel, School school,
                string castTime, string components,
                string range, string target,
                string duration, string savingThrow,
                string resistance, string description, 
                int numOfDice, int diceSize, int additionalMod,
                int additionalDicePerLevel);
    int rollDice();
    bool cast(int desiredLevel); // display information about the spell to the user.

};

/********
 * This will contain any spells that are general in type such that
 * the user only needs to know what happens when the spell is cast,
 * and no rolls are made.
 *******/
class InfoSpell : private Spell
{
  public:
    ~InfoSpell() {}
    InfoSpell(int minLevel, School school,
                string castTime, string components,
                string range, string target,
                string duration, string savingThrow,
                string resistance, string description);
    bool cast(int desiredLevel); // display information about the spell to the user.

};

/*********
 * This will contain any spells that requires a random roll of the dice
 * to be made in order for the spell to be cast.
 ********/
class RandomSpell : private Spell
{
  protected:
    int numOfDice;      //number of dice to be rolled in the spell
    int diceSize;       //number of sides on the dice rolled
    int additionalMod;  //any additional modifiers

    // TODO
    // make randomized roll display different spell outcome
    
  public:
    ~RandomSpell() {}
    RandomSpell(int minLevel, School school,
                string castTime, string components,
                string range, string target,
                string duration, string savingThrow,
                string resistance, string description, 
                int numOfDice, int diceSize, int additionalMod);
    int rollDice();
    bool cast(int desiredLevel); // display information about the spell to the user.

};

class Spellbook : private Spell
{
  protected:     
    int maxSpellSlots[10];
    int currentSpellSlots[10];

    public:
        ~Spellbook() {}
		Spellbook();
};


#endif // SPELLBOOK_H