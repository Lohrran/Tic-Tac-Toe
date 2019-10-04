#include "MenuSystem.h"

void MenuSystem::init(GameObject* obj)
{
	eventChannel->subscribe(this, &MenuSystem::onButtonEvent);
}

void MenuSystem::update(GameObject* obj){ }

void MenuSystem::free(GameObject* obj){ }

void MenuSystem::onButtonEvent(ButtonEvent* button)
{
	information->setScene(button->name);
	gameScreenManagement->loadScene(button->name);
}