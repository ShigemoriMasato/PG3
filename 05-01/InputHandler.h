#pragma once
#include "ICommand.h"

class InputHandler {
public:

	~InputHandler();

	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();

private:

	ICommand* moveLeftCommand_;
	ICommand* moveRightCommand_;

};
