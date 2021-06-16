#ifndef NATION_H
#define NATION_H

#include <cstdint>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <vector>
#include "texture.hpp"

typedef uint16_t NationId;

/**
 * Defines a one side relation between a country
 * This allows for cases where a country A hates country B, but country B loves country A
 */
class NationRelation {
public:
	float relation;
	// Interest of a nation on this nation
	float interest;

	// Whetever commercial operations are allowed on on the target country
	bool has_embargo;
	bool has_war;
	bool has_alliance;
	bool has_defensive_pact;
	bool has_truce;
	bool has_embassy;
	bool has_military_access;
	bool has_market_access;
};

#include "policy.hpp"

enum IdeologyType {
	// Primary types
	MONARCHY,
	ANARCHY,
	DEMOCRACY,
	COMMUNISM,
	FASCISM,
	REPUBLIC,
};

#include "province.hpp"
class Event;
class Nation {
	inline void do_diplomacy();
	inline bool can_do_diplomacy();
public:
	Nation() {};
	Nation& operator=(const Nation&) = default;
	~Nation() {
		delete default_flag;
	};

	// Whetever thet nation exists at all - we cannot add nations in-game
	// so we just check if the nation "exists" at all, this means that it has
	// a presence and a goverment, must own atleast 1 province
	inline bool exists() {
		return owned_provinces.size() > 0;
	}

	// Whetever this nation is controlled by AI
	bool controlled_by_ai;

	// Default transleted/display name
	std::string name;

	// Default reference name
	std::string ref_name;

	// Default color of the country
	uint32_t color;

	// A list with relations with all other nations, mapped 1:1 to the Nation list in the world
	std::vector<NationRelation> relations;

	// Id of the nation that has us on their sphere of influence
	NationId spherer_id;

	// Number of diplomacy points available
	float diplomacy_points;

	// Total number of prestige
	float prestige = 0.1f;

	// Base literacy applied to all pops
	float base_literacy;

	// Determines if the nation is civilized
	bool is_civilized;

	// Level of infamy
	float infamy = 0.f;

	// 3 key scores used to define a nation's minimum prestige, how willing would the AI
	// be to challenge this nations and other valuable stuff
	float military_score = 0.f;
	float naval_score = 0.f;
	float economy_score = 0.f;

	// Total budget of the nation (money in ark), this is not equal to GDP, the GDP is the total sum of the price
	// of all products in the nation, which are volatile unless they are sold
	float budget;

	// Total GDP of the nation
	float gdp = 0.f;

	// Primary culture of this nation, may also be changed via events, otherwise it's permanent
	Culture * primary_culture = nullptr;

	// The capital of this nation (can be nullptr)
	Province * capital = nullptr;

	// Accepted cultures in this nation, the accepted cultures may have some bonuses on provinces *totally*
	// owned by this nation
	std::set<Culture *> accepted_cultures;

	// List of provinces which are owned by this nation (including partial ownership)
	std::set<Province *> owned_provinces;

	// List of neighbouring nations
	std::set<Nation *> neighbours;

	// A pointer to a class defining the current policy of this nation
	Policies current_policy;

	// Inbox of the nation; events that require our attention / should be processed
	std::deque<Event> inbox;

	// Default flag texture of the country
	Texture * default_flag = nullptr;

	// Time until a diplomatic action can be done
	uint16_t diplomatic_timer;

	void increase_relation(const World& world, Nation * target);
	void decrease_relation(const World& world, Nation * target);

	void auto_relocate_capital(void);
	
	void set_policy(Policies& policies);
};

#endif
