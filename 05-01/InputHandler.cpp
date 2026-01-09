#include "InputHandler.h"
#include "Player.h"
#include <Novice.h>

InputHandler::~InputHandler() {
	if (moveLeftCommand_) {
		delete moveLeftCommand_;
		moveLeftCommand_ = nullptr;
	}
	if (moveRightCommand_) {
		delete moveRightCommand_;
		moveRightCommand_ = nullptr;
	}
}

void InputHandler::AssignMoveLeftCommand2PressKeyA() {
	moveLeftCommand_ = new MoveLeftCommand();
}

void InputHandler::AssignMoveRightCommand2PressKeyD() {
	moveRightCommand_ = new MoveRightCommand();
}

ICommand* InputHandler::HandleInput() {
	char key[256];
	Novice::GetHitKeyStateAll(key);
	if (key[DIK_A] || key[DIK_LEFTARROW]) {
		return moveLeftCommand_;
	}
	if (key[DIK_D] || key[DIK_RIGHTARROW]) {
		return moveRightCommand_;
	}
	return nullptr;
}
