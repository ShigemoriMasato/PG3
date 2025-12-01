#pragma once
#include "IScene.h"
;
class TitleScene : public IScene {
public:
	TitleScene() = default;
	~TitleScene() override = default;

	std::unique_ptr<IScene> Update(bool trigger) override;
	void Draw() override;

private:

};
