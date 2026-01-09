#pragma once
#include <cstdint>
#include <vector>
#include "Unit.h"

enum SelectMode {
	SELECTOR,
	UNIT
};

class Selector {
public:

	Selector();
	~Selector();

	void Initialize();
	void Update();
	void Draw();

	int AddUnit();
	void RemoveUnit(int id);
	void Move(int x, int y);
	void SelectUnit();
	void DeSelectUnit();

	Unit* GetSelectUnit() {
		return selectUnit_;
	}

	SelectMode GetSelectMode() {
		return selectMode_;
	}

private:
	int mapX_ = 0;
	int mapY_ = 0;
	int mapSize_ = 40;

	SelectMode selectMode_;

	std::vector<Unit*> unit;
	Unit* selectUnit_;

};

