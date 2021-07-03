#ifndef ACTIONS_H
#define ACTIONS_H

#include "serializer.hpp"

enum ActionType {
	ACTION_PROVINCE_UPDATE,
	ACTION_PROVINCE_ADD,
	ACTION_PROVINCE_REMOVE,
	ACTION_PROVINCE_COLONIZE,

	ACTION_NATION_UPDATE,
	ACTION_NATION_ADD,
	ACTION_NATION_REMOVE,
	ACTION_NATION_COLONIZE,

	ACTION_UNIT_UPDATE,
	ACTION_UNIT_ADD,
	ACTION_UNIT_REMOVE,
	ACTION_UNIT_CHANGE_TARGET,

	// Tell client that a whole tick has been done :D
	ACTION_WORLD_TICK,

	// Gaming chatting
	ACTION_CHAT_MESSAGE,
	ACTION_CHAT_NICKNAME,

	// Testing
	ACTION_PING,
	ACTION_PONG,

	// Errors
	ACTION_BAD,
};

class Action {
public:
	enum ActionType type;
	
	Action(enum ActionType _type) : type(_type) {};
};

#endif
