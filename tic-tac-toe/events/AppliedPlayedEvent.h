#ifndef APPLIEDPLAYEDEVENT_H
#define APPLIEDPLAYEDEVENT_H

#include <string>

#include "Event.h"

struct AppliedPlayedEvent : public Event
{
	AppliedPlayedEvent (std::string turn = "", std::string position = "") : turn { turn }, position { position } { }

	std::string turn, position;
};
#endif