#ifndef PLAYEDEVENT_H
#define PLAYEDEVENT_H

#include "Event.h"
#include <string>

struct PlayedEvent : public Event
{
	PlayedEvent(std::string turn = "", std::string position = "") : turn{ turn }, position{ position } { }

	std::string turn, position;
};

#endif