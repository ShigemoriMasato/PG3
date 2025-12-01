#pragma once
#include "IScene.h"
;
class ClearScene : public IScene {
public:
	ClearScene() = default;
	~ClearScene() override = default;

	std::unique_ptr<IScene> Update(bool trigger) override;
	void Draw() override;

private:

};
