#pragma once
#include "Scene/IScene.h"
#include "InputHandler.h"
#include "Player.h"
#include <memory>

class StageScene : public IScene {
public:

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw() override;

private:

	std::unique_ptr<InputHandler> inputHandler_;
	std::unique_ptr<Player> player_;

};
