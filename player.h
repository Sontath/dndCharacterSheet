/***********************************
 * Player for a DnD campaign
 * 
 * Notes for a DnD || Pathfinder character
 * 
 ***********************************/

//TODO RENAME TO CHARACTER_H

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using namespace std;

 
struct CharacterDetail //Character Details and info
{
    string name;
    static string playerName; // Name of the owner of the program
    string race, nationality;
	string alignment;
    string deity;
    string size;
};

struct AbilityScores //Character ability scores
{
    int str, dex, con, intel, wis, cha;
    int strMod, dexMod, conMod, intelMod, wisMod, chaMod;
    int Tempstr, Tempdex, Tempcon, Tempintel, Tempwis, Tempcha;
    int TempstrMod, TempdexMod, TempconMod, TempintelMod, TempwisMod, TempchaMod;
};

struct CombatScores //Character combat oriented objects (AC, Attack Bonuses, Initiave)
{
	int playerLevel;
    int AC, touchAC, flatFootAC;
    int initiative;
    int baseAttkBonus, meleeAttkBonus, rangedAttkBonus;
    // ARRAY OF ATTACKS/WEAPONS
	// NOTE HANDLE RESISTANCES
};

struct HealthScores //Character Hit Dice and Hit Points
{
    int maxNumOfHD, currentHD, HDDiceSize;
    int maxHealth, currentHealth;
};

struct SpellcastingScores //Character spell failure, spell save's DC, and spell resistance
{
    float spellFail;
    int spellResistance, spellSaveDCMod;
};

struct Experience //Character experience and amount needed for next level
{
    int xp, nextLevel;
};

struct Inventory //Character inventory, weight, and gold
{
    int gold;
	int weight;
	vector<string> inventory;
};

struct Abilities //Character special abilities and feats
{
	string ability, feat;
};

/**********************
* Player needs:
* character level 
* remaining spell slots
* total spell slots
**********************/
class Character
{
private:
    CharacterDetail charecterDetails;
    AbilityScores abilityScores;
    CombatScores combatScores;
    HealthScores healthScores;
    SpellcastingScores spellcastinScores;
    Experience experience;
    Inventory inventory;
    Abilities abilities;
    
    // TODO
    // Skill stuff

public:
    ~Character() {}
    Character() {}
    
    // Resting
    void LongRest();
    void ShortRest(int hitDice);

    // Cast Spells
    bool castSpell(Spell spell);
};

#endif // PLAYER_H