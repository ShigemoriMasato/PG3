#include "Selector.h"
#include <Novice.h>

Selector::Selector() {
	selectMode_ = SELECTOR;
}

Selector::~Selector() {
	for (auto& u : unit) {
		delete u;
		u = nullptr;
	}
}

void Selector::Initialize() {
	mapX_ = 0;
	mapY_ = 0;
	mapSize_ = 32;
	selectMode_ = SELECTOR;
	unit = {};
	selectUnit_ = nullptr;

	for (int i = 0; i < 5; ++i)
		AddUnit();
}

void Selector::Update() {
}

void Selector::Draw() {
	for (int i = 0; i < 1280 / mapSize_; i++) {
		Novice::DrawBox(i * mapSize_, 0, mapSize_, 720, 0.0f, WHITE, kFillModeWireFrame);
	}

	for (int i = 0; i < 720 / mapSize_; i++) {
		Novice::DrawBox(0, i * mapSize_, 1280, mapSize_, 0.0f, WHITE, kFillModeWireFrame);
	}

	int leftTopX = mapX_ * mapSize_ - 1;
	int leftTopY = mapY_ * mapSize_ - 1;
	Novice::DrawBox(leftTopX, leftTopY, mapSize_ + 2, mapSize_ + 2, 0.0f, 0xff8000ff, kFillModeWireFrame);

	for (const auto& u : unit) {
		u->Draw();
	}
}

int Selector::AddUnit() {
	int id = static_cast<int>(unit.size());
	Unit* newUnit = new Unit(this);

	int x, y;
	while (true) {
		x = rand() % (1280 / mapSize_);
		y = rand() % (720 / mapSize_);

		bool overlap = false;
		for (const auto& u : unit) {
			auto [unitX, unitY] = u->GetPosition();
			if (unitX == x && unitY == y) {
				x = -1;
				overlap = true;
				break;
			}
		}

		if (!overlap) {
			break;
		}
	}

	newUnit->Initialize(id, x, y);
	unit.push_back(newUnit);

	return id;
}

void Selector::RemoveUnit(int id) {
	for (size_t i = 0; i < unit.size(); ++i) {
		if (unit[i]->GetID() == id) {
			delete unit[i];
			unit.erase(unit.begin() + i);
			break;
		}
	}
}

void Selector::Move(int x, int y) {
	mapX_ += x;
	mapY_ += y;
}

void Selector::SelectUnit() {
	for (const auto& u : unit) {
		auto [unitX, unitY] = u->GetPosition();
		if (unitX == mapX_ && unitY == mapY_) {
			selectUnit_ = u;
			selectMode_ = UNIT;
			u->SetSelected(true);
		}
	}

}

void Selector::DeSelectUnit() {
	if (selectUnit_ != nullptr) {
		selectUnit_->SetSelected(false);
		selectUnit_ = nullptr;
		selectMode_ = SELECTOR;
	}
}
