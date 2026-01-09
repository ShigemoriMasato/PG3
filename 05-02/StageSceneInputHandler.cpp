#include "StageSceneInputHandler.h"
#include "SelectorCommand.h"
#include <Novice.h>

StageSceneInputHandler::StageSceneInputHandler() {
}

void StageSceneInputHandler::UpdateKeyState() {
	memcpy(preKey, key, 256);
	Novice::GetHitKeyStateAll(key);
}

IStageSceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit) {
	unit_ = unit;
	if (key[DIK_W] && !preKey[DIK_W]) {
		return new UnitMoveCommand(unit_, 0, -1);
	}
	if (key[DIK_S] && !preKey[DIK_S]) {
		return new UnitMoveCommand(unit_, 0, 1);
	}
	if (key[DIK_A] && !preKey[DIK_A]) {
		return new UnitMoveCommand(unit_, -1, 0);
	}
	if (key[DIK_D] && !preKey[DIK_D]) {
		return new UnitMoveCommand(unit_, 1, 0);
	}
	if (key[DIK_SPACE] && !preKey[DIK_SPACE]) {
		return new UnitMoveEndCommand(unit_, selector_);
	}
	return nullptr;
}

IStageSceneCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector) {
	selector_ = selector;

	if (key[DIK_W] && !preKey[DIK_W]) {
		return new SelectorMoveCommand(selector_, 0, -1);
	}
	if (key[DIK_S] && !preKey[DIK_S]) {
		return new SelectorMoveCommand(selector_, 0, 1);
	}
	if (key[DIK_A] && !preKey[DIK_A]) {
		return new SelectorMoveCommand(selector_, -1, 0);
	}
	if (key[DIK_D] && !preKey[DIK_D]) {
		return new SelectorMoveCommand(selector_, 1, 0);
	}
	if (key[DIK_SPACE] && !preKey[DIK_SPACE]) {
		return new SelectUnitCommand(selector_);
	}
	return nullptr;
}
