#include "VictorySystem.h"

void VictorySystem::init(GameObject* obj)
{
	vic = false;
	eventChannel->subscribe(this, &VictorySystem::onVictoryEvent);
}

void VictorySystem::update(GameObject* obj) 
{
	if (vic)
	{
		information->setVictory(winner);
		gameScreenManagement->loadScene("Game Over Menu");
		vic = false;
	}
}

void VictorySystem::free(GameObject* obj) { }

void VictorySystem::onVictoryEvent(VictoryEvent* victory)
{
	winner = victory->sign;
	vic = true;
}