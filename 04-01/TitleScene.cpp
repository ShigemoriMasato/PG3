#include "TitleScene.h"
#include <Novice.h>
#include "GameScene.h"

std::unique_ptr<IScene> TitleScene::Update(bool trigger) {
	if (trigger) {
		return std::make_unique<GameScene>();
	}

	return nullptr;
}

void TitleScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xBBBBFFFF, kFillModeSolid);
	Novice::ScreenPrintf(300, 350, "TITLE SCENE");
}
