#ifndef GAMEOVERSYSTEM_H
#define GAMEOVERSYSTEM_H

// Engine
#include "GameScreenManagement.h"

// ECS
#include "Requeriment.h"

// Components
#include "PositionComponent.h"
#include "NameComponent.h"

// Events
#include "ButtonEvent.h"

// Transpose Information
#include "Information.h"

class GameOverSystem : public Requeriment<NameComponent, PositionComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;
	
	private:
		void onButtonEvent(ButtonEvent* button);

		std::shared_ptr<GameScreenManagement> gameScreenManagement = GameScreenManagement::get();

		std::shared_ptr<Information> information = Information::get();
};
#endif