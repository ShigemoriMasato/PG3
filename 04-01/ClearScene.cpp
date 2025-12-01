#include "ClearScene.h"
#include "TitleScene.h"
#include <Novice.h>

std::unique_ptr<IScene> ClearScene::Update(bool trigger) {

	if (trigger) {
		return std::make_unique<TitleScene>();
	}

	return nullptr;
}

void ClearScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xFFBBBBFF, kFillModeSolid);
	Novice::ScreenPrintf(300, 350, "CLEAR SCENE");
}
