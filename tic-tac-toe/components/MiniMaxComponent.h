#ifndef MINIMAXCOMPONENT_H
#define MINIMAXCOMPONENT_H

#include "Component.h"

struct MiniMaxComponent : public Component
{
	MiniMaxComponent(int depth = 0, bool start = false) : depth{ depth }, start{ start } { }

	int depth;
	bool start;
};
#endif