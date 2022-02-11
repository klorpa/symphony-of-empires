// Symphony of Empires
// Copyright (C) 2021, Symphony of Empires contributors
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// ----------------------------------------------------------------------------
// Name:
//      unit.hpp
//
// Abstract:
//      Does some important stuff.
// ----------------------------------------------------------------------------

#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <type_traits>
#include "good.hpp"
#include "nation.hpp"
#include "unified_render/entity.hpp"
#include "unified_render/decimal.hpp"

// Defines a type of unit, it can be a tank, garrison, infantry, etc
// this is moddable via a lua script and new unit types can be added
class UnitType : public RefnameEntity<uint8_t> {
public:
    //UnitType();
    //~UnitType();

    DECIAML_TYPE_3P supply_consumption;
    DECIAML_TYPE_3P speed;
    DECIAML_TYPE_3P max_health;
    DECIAML_TYPE_3P defense;
    DECIAML_TYPE_3P attack;

    // Max ticks allowed for defensive bonus - this basically prevents an unit from staying 200
    // years on the same spot and be fucking indestructible
    uint64_t max_defensive_ticks;

    // The defense provided by the unit each tick for staying on the same position
    // aka. digging trenches
    DECIAML_TYPE_3P position_defense;

    // Capacity of units that can be carried (transport units)
    size_t capacity;

    // Time needed to build
    size_t build_time;

    // Can go on ground?
    bool is_ground;
    
    // Can go on water?
    bool is_naval;

    // Required goods, first describes the id of the good and the second describes how many
    std::vector<std::pair<Good *, size_t>> req_goods;
};

// A trait for an unit; given randomly per each recruited unit
class UnitTrait : public RefnameEntity<uint8_t> {
public:
    //UnitTrait();
    //~UnitTrait();
    
    DECIAML_TYPE_3P supply_consumption_mod;
    DECIAML_TYPE_3P speed_mod;
    DECIAML_TYPE_3P max_health_mod;
    DECIAML_TYPE_3P defense_mod;
    DECIAML_TYPE_3P attack_mod;
    DECIAML_TYPE_3P morale_mod;
};

// Roughly a batallion, consisting of approximately 500 soldiers each
class Unit : public IdEntity<uint16_t> {
public:
    //Unit();
    //~Unit();

    void attack(Unit& enemy);
    std::pair<int, int> get_pos(void) const;
    void set_target(Province& province);
    float get_speed(const Province& province) const;
    float get_speed(void) const;
    void set_province(Province& province);
    bool can_move(void) const;
    
    // Type of unit
    UnitType* type;

    // Size of the unit (soldiers in unit)
    size_t size;
    // Base size of the unit (max size due to anti-attrition)
    size_t base;
    
    Province* target = nullptr,* province = nullptr;
    DECIAML_TYPE_3P move_progress;

    // Who owns this unit
    Nation* owner;

    DECIAML_TYPE_3P morale;

    // For perspective, 0.5 is the normal unit (i.e a soldier POP)
    DECIAML_TYPE_3P experience;

    // Used to "ignore" an unit when doing any check, this allows other units to
    // attack this unit
    bool ignore_tag;

    // The ticks the unit has not been moved
    uint64_t defensive_ticks;

    // Available supplies, 1.0 is all supplies fullfilled, lower than that and the unit starts shrinking
    DECIAML_TYPE_3P supply;

    // Money that the unit has
    DECIAML_TYPE_3P budget;
    
    std::vector<UnitTrait*> traits;

    // TODO: ser/deser
    bool on_battle = false;
};