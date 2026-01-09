#pragma once
#include "ICommand.h"

class MoveRightCommand : public ICommand {
	void Execute(Player& player) override;
};

class MoveLeftCommand : public ICommand {
	void Execute(Player& player) override;
};

class Player {
public:

	void Initialize();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();

private:

	int positionX_;
	int positionY_;

	int width_;
	int height_;

};
