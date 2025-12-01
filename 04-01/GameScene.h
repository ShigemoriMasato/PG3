#pragma once
#include "IScene.h"
;
class GameScene : public IScene {
public:
	GameScene() = default;
	~GameScene() override = default;

	std::unique_ptr<IScene> Update(bool trigger) override;
	void Draw() override;

private:

};
