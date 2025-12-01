#include "GameScene.h"
#include "ClearScene.h"
#include <Novice.h>

std::unique_ptr<IScene> GameScene::Update(bool trigger) {

	if (trigger) {
		return std::make_unique<ClearScene>();
	}

	return nullptr;
}

void GameScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xBBFFBBFF, kFillModeSolid);
	Novice::ScreenPrintf(300, 350, "GAME SCENE");
}
