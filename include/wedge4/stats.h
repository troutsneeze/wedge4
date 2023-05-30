#ifndef WEDGE4_STATS_H
#define WEDGE4_STATS_H

#include "wedge4/main.h"

namespace wedge {

enum Status_Condition // "Status" interferes with X11
{
	STATUS_OK = 0,
	STATUS_SIZE // start your custom statuses with this
};

enum Weak_Strong
{
	WEAK_STRONG_NONE = 0,
	WEAK_STRONG_SIZE // start your custom strengths/weaknesses with this
};

class WEDGE4_EXPORT Fixed_Stats
{
public:
	Fixed_Stats();
	Fixed_Stats(util::JSON::Node *json);
	std::string save();
	Fixed_Stats &operator+=(const Fixed_Stats &rhs);

	int max_hp;
	int max_mp;
	int attack;
	int defence;

	void set_extra(int index, int value); // automatically sizes vector with zeroes
	int get_extra(int index) const;
	
	int weakness;
	int strength;

protected:
	std::vector<int> extra; // game-defined stats
};

class WEDGE4_EXPORT Base_Stats
{
public:
	Base_Stats();
	Base_Stats(util::JSON::Node *json);
	std::string save();

	Fixed_Stats fixed;

	int status;
	int hp;
	int mp;
	
	std::vector<std::string> get_spells();
	void add_spell(std::string name); // sorts
	std::string spell(int index);
	int num_spells();

	void set_extra(int index, int value); // automatically sizes vector with zeroes
	int get_extra(int index) const;

	void set_name(std::string name);
	std::string get_name();

protected:
	std::vector<std::string> spells; // only used by players
	std::vector<int> extra; // game-defined stats
	std::string name;
};

class WEDGE4_EXPORT Weapon_Stats
{
public:
	Weapon_Stats();
	Weapon_Stats(int id);
	Weapon_Stats(util::JSON::Node *json);
	std::string save();

	int id;

	Fixed_Stats stats;

private:
};

class WEDGE4_EXPORT Armour_Stats
{
public:
	Armour_Stats();
	Armour_Stats(int id);
	Armour_Stats(util::JSON::Node *json);
	std::string save();

	int id;

	Fixed_Stats stats;

private:
};

class WEDGE4_EXPORT Player_Stats
{
public:
	Player_Stats();
	Player_Stats(util::JSON::Node *json);
	std::string save();

	int level;
	int experience;
	Base_Stats base;

	Weapon_Stats weapon;
	int weapon_index;
	Armour_Stats armour;
#if 0
	int armour_index;
#endif

	gfx::Sprite *sprite;
};

}

#endif // WEDGE4_STATS_H
