#include "StageScene.h"

StageScene::~StageScene() {
	for (auto& command : commandHistory_) {
		delete command;
		command = nullptr;
	}
}

void StageScene::Initialize() {
	inputHandler_ = std::make_unique<StageSceneInputHandler>();
	selector_ = std::make_unique<Selector>();
	selector_->Initialize();
}

void StageScene::Update() {
	inputHandler_->UpdateKeyState();

	SelectMode mode = selector_->GetSelectMode();
	if (mode == SELECTOR) {
		command_ = inputHandler_->SelectorHandleInput(selector_.get());
	} else if (mode == UNIT) {
		command_ = inputHandler_->UnitHandleInput(selector_->GetSelectUnit());
	}

	if (command_) {
		command_->Execute();
			commandHistory_.push_back(command_);
	}

	memcpy(preKey, key, 255);
	Novice::GetHitKeyStateAll(key);
	if (key[DIK_Z] && !preKey[DIK_Z] &&key[DIK_LCONTROL]) {
		if (!commandHistory_.empty()) {
			commandHistory_.back()->Undo();
			delete commandHistory_.back();
			commandHistory_.pop_back();
		}
	}

	selector_->Update();
}

void StageScene::Draw() {
	selector_->Draw();
}
