#pragma once
#include "IScene.h"
;
class SceneManager {
public:

	SceneManager();
	~SceneManager() = default;

	void Update(bool trigger);
	void Draw();

private:

	std::unique_ptr<IScene> currentScene_ = nullptr;
	std::unique_ptr<IScene> nextScene_ = nullptr;

};
