#pragma once
#include "IStageSceneCommand.h"
#include "Unit.h"
#include "Selector.h"

class StageSceneInputHandler {
public:

	StageSceneInputHandler();
	~StageSceneInputHandler() = default;

	void UpdateKeyState();

	IStageSceneCommand* UnitHandleInput(Unit* unit);
	IStageSceneCommand* SelectorHandleInput(Selector* selector);

private:

	char key[256];
	char preKey[256];

	Unit* unit_;
	Selector* selector_;

};
