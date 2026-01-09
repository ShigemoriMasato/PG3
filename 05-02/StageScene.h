#pragma once
#include "Scene/IScene.h"
#include "Selector.h"
#include "StageSceneInputHandler.h"
#include <memory>
#include <list>

class StageScene : public IScene {
public:

	~StageScene() override;

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:

	std::unique_ptr<StageSceneInputHandler> inputHandler_;
	std::unique_ptr<Selector> selector_;
	std::list<IStageSceneCommand*> commandHistory_;
	std::list<IStageSceneCommand*>::iterator commandHistoryItr_;

	char key[255];
	char preKey[255];

	IStageSceneCommand* command_ = nullptr;

};
