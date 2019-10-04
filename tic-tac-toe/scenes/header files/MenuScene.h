#ifndef MENUSCENE_H
#define MENUSCENE_H

// Engine
#include "GameScene.h"

// ECS
#include "Scene.h"
#include "Resources.h"

// Components
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "NameComponent.h"
#include "ButtonComponent.h"

// Systems
#include "SpriteSystem.h"
#include "MenuSystem.h"
#include "ButtonSystem.h"

class MenuScene : public GameScene
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
};
#endif