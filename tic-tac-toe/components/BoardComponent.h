#ifndef BOARDCOMPONENT_H
#define BOARDCOMPONENT_H

#include "Component.h"

struct BoardComponent : public Component
{
	BoardComponent(int x = 0, int y = 0, int height = 0, int width = 0) : 
		x{ x }, y{ y },
			height{ height }, width{ width } { }
	
	int x, y;
	int height, width;
};
#endif