/***********************************
 * This is the shield of the character
 * 
 * Notes for DnD || Pathfinder shield
 * 
 ***********************************/

#ifndef SHIELD_H
#define SHIELD_H

#include <string>

using namespace std;

class Shield
{
  protected:
	int shieldAC;           //this is the shield's Armor Bonus to be applied to armor
	string name;            //this is the name of the shield
	short armorPenalty;     //this is the armor check penalty applied to the skills
	float spellFail;        //this is the arcane spell failure of the shield
	int weight;             //this is the weight of the shield
    string properties;      //this is for special properties of the shield

  public:
    ~Shield() {}
    Shield() {}
    
    // Getters
    int getShieldAC() { return shieldAC; }
    string getName() { return name; }
    string getProperties() { return properties; }
    short getArmorPenalty() { return armorPenalty; }
    float getSpellFail() { return spellFail; }
    int getWeight() { return weight; }
    string getProperties() { return properties; }

    // Setters
	void setShieldAC(int shieldAC) { this->shieldAC = shieldAC; }
	void setName(string name) { this->name = name; }
    void setProperties(string properties) { this->properties = properties; }
    void setArmorPenalty(short armorPenalty) { this->armorPenalty = armorPenalty; }
    void setSpellFail(float spellFail) { this->name = name; }
    void setWeight(int weight) { this->weight = weight; }
    void setProperties(string properties) { this->properties = properties; }
};

#endif // SHIELD_H