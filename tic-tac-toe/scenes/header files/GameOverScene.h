#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

// Engine
#include "GameScene.h"

// ECS
#include "Scene.h"
#include "Resources.h"

// Transpose Information
#include "Information.h"

// Components
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "NameComponent.h"
#include "ButtonComponent.h"

// Systems
#include "SpriteSystem.h"
#include "ButtonSystem.h"
#include "GameOverSystem.h"

class GameOverScene : public GameScene
{
	public:
		void Initialize() override;
		void Start() override;
		void Input() override;
		void Update() override;
		void Free() override;

	private:
		Scene* scene;
		Resources* resources;

		std::shared_ptr<Information> information = Information::get();
};
#endif