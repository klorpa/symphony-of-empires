#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include "nation.hpp"
#include "economy.hpp"
#include "lua.hpp"

class Tile {
public:
	size_t owner_id;
	size_t province_id;
	uint8_t elevation;
	uint8_t infra_level;
};

#include <string>
#include "province.hpp"

class Unit {
public:
	float x;
	float y;
	float health;
	size_t owner_id;
};

class World {
public:
	World() {};
	World(const char * topo_map, const char * pol_map, const char * div_map, const char * infra_map);
	World& operator=(const World&) = default;
	~World();

	void do_tick();
	void add_good(Good * good);
	void add_industry_type(IndustryType * it);
	void add_nation(Nation * nation);
	void add_province(Province * province);

	size_t sea_level;
	
	size_t width;
	size_t height;

	Tile * tiles;

	std::vector<Unit *> units;
	std::vector<Good *> goods;
	std::vector<IndustryType *> industry_types;
	std::vector<Nation *> nations;
	std::vector<Province *> provinces;
	std::vector<Company *> companies;
	std::vector<Product *> products;
	std::vector<PopType *> pop_types;
	std::vector<Religion *> religions;
	std::vector<Culture *> cultures;
	std::vector<LuaAPI::Event *> events;
	lua_State * lua;

	uint64_t time;
};

#endif
