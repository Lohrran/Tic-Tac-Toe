#ifndef VICTORYSYSTEM_H
#define VICTORYSYSTEM_H

// Engine
#include "GameScreenManagement.h"

// ECS
#include "Requeriment.h"

// Transpose Information
#include "Information.h"

// Components
#include "PositionComponent.h"
#include "NameComponent.h"

#include "SpriteComponent.h"
#include "ButtonComponent.h"

// Events
#include "VictoryEvent.h"

class VictorySystem : public Requeriment <NameComponent, PositionComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;

	private:
		void onVictoryEvent(VictoryEvent* victory);

		std::shared_ptr<GameScreenManagement> gameScreenManagement = GameScreenManagement::get();
		std::shared_ptr<Information> information = Information::get();

		std::string winner;
		bool vic;
};
#endif