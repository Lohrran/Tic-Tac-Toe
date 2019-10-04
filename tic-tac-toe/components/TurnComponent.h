#ifndef TURNCOMPONENT_H
#define TURNCOMPONENT_H

#include "Component.h"
#include <string>

struct TurnComponent : public Component
{
	TurnComponent(std::string currentTurn = "", std::string nextTurn = "") : currentTurn{ currentTurn }, nextTurn{ nextTurn } { }

	std::string currentTurn, nextTurn;
};

#endif