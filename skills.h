#ifndef SKILLS_H
#define SKILLS_H

#include <string>

using namespace std;

class Skill
{
  private:
    string name;
    string keyAbility;
	int keyAbilityModifier;
	int ranks;
	int miscMod;
	short armorPenalty;

};

class KnownSkill : private Skill
{

};

class LearnedSkill : private Skill
{

};

class DoubleSkill: private Skill
{
    static const int multiplier = 2;
};

#endif // SKILLS_H