#ifndef SPAWNCOMPONENT_H
#define SPAWNCOMPONENT_H

#include "Component.h"
#include "GameObject.h"
#include <string>

struct SpawnComponent : public Component
{
	SpawnComponent() { }
	void add(std::string name, GameObject* obj) { spawnableds.insert(std::make_pair(name, obj)); } //Helper

	std::map<std::string, GameObject*> spawnableds;
};

#endif