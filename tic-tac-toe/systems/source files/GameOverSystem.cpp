#include "GameOverSystem.h"

void GameOverSystem::init(GameObject* obj)
{
	eventChannel->subscribe(this, &GameOverSystem::onButtonEvent);
}

void GameOverSystem::update(GameObject* obj)
{

}

void GameOverSystem::free(GameObject* obj)
{

}

void GameOverSystem::onButtonEvent(ButtonEvent* button)
{
	if (button->name == "Restart")
	{
		gameScreenManagement->loadScene(information->getPreviousScene());
	}

	else if (button->name == "Home")
	{
		gameScreenManagement->loadScene("Home Menu");
	}
}