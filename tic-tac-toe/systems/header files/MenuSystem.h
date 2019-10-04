#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

// Engine
#include "GameScreenManagement.h"

// ECS
#include "Requeriment.h"

// Transpose Information
#include "Information.h"

// Component
#include "PositionComponent.h"
#include "NameComponent.h"

// Event
#include "ButtonEvent.h"

class MenuSystem : public Requeriment<PositionComponent, NameComponent>
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