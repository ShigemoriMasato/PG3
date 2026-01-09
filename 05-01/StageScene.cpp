#include "StageScene.h"

void StageScene::Initialize() {
	inputHandler_ = std::make_unique<InputHandler>();
	player_ = std::make_unique<Player>();
	player_->Initialize();

	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();
}

void StageScene::Update() {
	auto cmd = inputHandler_->HandleInput();
	if (cmd) {
		cmd->Execute(*player_);
	}
}

void StageScene::Draw() {
	player_->Draw();
}
