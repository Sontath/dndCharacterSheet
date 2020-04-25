#include "spellbook.h"
#include <iostream>
#include <random>

using namespace std;

RolledSpell :: RolledSpell(int level, School school,
                string castTime, string components,
                string range, string target,
                string duration, string savingThrow,
                string resistance, string description,
                int numOfDice, int diceSize, int additionalMod,
                int additionalDicePerLevel)
{
    this->minLevel = level;
    this->school = school;
    this->castTime = castTime;
	this->components = components;
	this->range = range;
	this->target = target;
	this->duration = duration;
	this->savingThrow = savingThrow;
    this->numOfDice = numOfDice;
    this->diceSize = diceSize;
    this->additionalMod = additionalMod;
    this->additionalDicePerLevel = additionalDicePerLevel;
}

int RolledSpell :: rollDice()
{
    int count = 0;

    for (int i = 0; i < this->numOfDice; i++)
    {
        count += rand() % this->diceSize;
    }

    count += this->additionalMod;

    return count;
}

/**********************
* first, display spell school
* second, display spell level
* third, display casting time
* fourth, display components
* fifth, display range, target, and duration
* sixth, display description
* seventh, roll the dice of spell if necessary || possible
**********************/
bool RolledSpell :: cast(int desiredLevel)
{
    // test if desired level if high enough, if not, warns user that they are unable to cast the spell
    if (desiredLevel < minLevel)
    {
        cout << "You are unable to cast this spell" << endl;
        return false;
    }
    
    cout << "School: " << this->school << endl;
    cout << "Level: " << desiredLevel << endl;
    cout << "Cast time: " << this->castTime << endl;
    cout << "Components: " << this->components << endl;
    cout << "Range: " << this->range << ", Target: " << this->target << " Duration: " << this->duration << endl;
    cout << "Description: " << this->description << endl;
	cout << "Total Rolled: " << this->rollDice() << endl;
	return true;
}

InfoSpell :: InfoSpell(int level, School school,
                string castTime, string components,
                string range, string target,
                string duration, string savingThrow,
                string resistance, string description)
{
	this->minLevel = level;
    this->school = school;
    this->castTime = castTime;
	this->components = components;
	this->range = range;
	this->target = target;
	this->duration = duration;
	this->savingThrow = savingThrow;
    this->resistance = resistance;
	this->description = description;
}

bool InfoSpell :: cast(int desiredLevel)
{
    // test if desired level if high enough, if not, warns user that they are unable to cast the spell
    if (desiredLevel < minLevel)
    {
        cout << "You are unable to cast this spell" << endl;
        return false;
    }
    
    cout << "School: " << this->school << endl;
    cout << "Level: " << desiredLevel << endl;
    cout << "Cast time: " << this->castTime << endl;
    cout << "Components: " << this->components << endl;
    cout << "Range: " << this->range << ", Target: " << this->target << " Duration: " << this->duration << endl;
    cout << "Description: " << this->description << endl;

	return true;
}