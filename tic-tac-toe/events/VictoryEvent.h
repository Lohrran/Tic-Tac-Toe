#ifndef VICTORYEVENT_H
#define VICTORYEVENT_H

#include "Event.h"

#include <string>

struct VictoryEvent : public Event
{
	VictoryEvent(std::string sign = "") : sign{ sign } { }

	std::string sign;
};

#endif