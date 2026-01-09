#pragma once
#include <utility>

class Selector;

class Unit {
public:

	Unit(Selector* selector);

	void Initialize(int id, int x, int y);
	void Update();
	void Draw();

	void Move(int x, int y);
	void MoveEnd();

	std::pair<int, int> GetPosition() const {
		return { mapX_, mapY_ };
	}

	void SetSelected(bool isSelected) {
		isSelected_ = isSelected;
	}

	int GetID() const {
		return id_;
	}

private:

	int mapX_ = 0;
	int mapY_ = 0;
	int mapSize_ = 32;
	int id_ = 0;
	bool isSelected_ = false;

	Selector* selector_;

};
