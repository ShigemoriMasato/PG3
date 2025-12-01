#include "SceneManager.h"
#include "TitleScene.h"

SceneManager::SceneManager() {
	currentScene_ = std::make_unique<TitleScene>();
}

void SceneManager::Update(bool trigger) {
	if (nextScene_) {
		currentScene_ = std::move(nextScene_);
	}
	nextScene_ = currentScene_->Update(trigger);
}

void SceneManager::Draw() {
	currentScene_->Draw();
}
