/***********************************
 * This is the armor, defenses, and resistances of the character
 * 
 * Notes for DnD || Pathfinder defenses
 * 
 ***********************************/

#ifndef ARMOR_H
#define ARMOR_H

#include <string>

using namespace std;

class Armor
{
  protected:
	int armorAC;           //this is the armor's Armor Bonus to be applied to armor
	string name;            //this is the name of the armor
	short armorPenalty;     //this is the armor check penalty applied to the skills
	float spellFail;        //this is the arcane spell failure of the armor
	int weight;             //this is the weight of the armor
    string properties;      //this is for special properties of the armor

  public:
    ~Armor() {}
    Armor() {}
    
    // Getters
    int getArmorAC() { return armorAC; }
    string getName() { return name; }
    string getProperties() { return properties; }
    short getArmorPenalty() { return armorPenalty; }
    float getSpellFail() { return spellFail; }
    int getWeight() { return weight; }
    string getProperties() { return properties; }

    // Setters
	void setArmorAC(int armorAC) { this->armorAC = armorAC; }
	void setName(string name) { this->name = name; }
    void setProperties(string properties) { this->properties = properties; }
    void setArmorPenalty(short armorPenalty) { this->armorPenalty = armorPenalty; }
    void setSpellFail(float spellFail) { this->name = name; }
    void setWeight(int weight) { this->weight = weight; }
    void setProperties(string properties) { this->properties = properties; }
};

#endif ARMOR_H