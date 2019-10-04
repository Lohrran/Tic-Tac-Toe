#ifndef PLAYERVSCOMPSCENE_H
#define PLAYERVSCOMPSCENE_H

// Engine
#include "GameScene.h"

// ECS
#include "Scene.h"
#include "Resources.h"

// Components
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "TagComponent.h"
#include "MouseComponent.h"

#include "NameComponent.h"
#include "TurnComponent.h"
#include "SpawnComponent.h"
#include "BoardComponent.h"
#include "MiniMaxComponent.h"

// Systems
#include "SpriteSystem.h"
#include "MouseSystem.h"

#include "ApplyPlayedSystem.h"
#include "GameSystem.h"
#include "PlayedMouseSystem.h"
#include "MiniMaxSystem.h"

#include "VictorySystem.h"

class PlayerVsCompScene : public GameScene
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
		std::shared_ptr<Camera> camera = Camera::get();
};
#endif