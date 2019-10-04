#ifndef TURNEVENT_H
#define TURNEVENT_H

#include "Event.h"
#include <string>

struct TurnEvent : public Event
{
	TurnEvent(std::string turn = "") : turn{ turn } { }

	std::string turn;
};

#endif