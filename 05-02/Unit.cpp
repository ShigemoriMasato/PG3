#include "Unit.h"
#include "Selector.h"
#include <Novice.h>

Unit::Unit(Selector* selector) {
	selector_ = selector;
}

void Unit::Initialize(int id, int x, int y) {
	id_ = id;
	mapX_ = x;
	mapY_ = y;
}

void Unit::Update() {
}

void Unit::Draw() {
	int leftTopX = mapX_ * mapSize_ + 2;
	int leftTopY = mapY_ * mapSize_ + 2;
	int size = mapSize_ - 4;
	Novice::DrawBox(leftTopX, leftTopY, size, size, 0.0f, isSelected_ ? RED : WHITE, kFillModeSolid);
}

void Unit::Move(int x, int y) {
	mapX_ += x;
	mapY_ += y;
	selector_->Move(x, y);
}

void Unit::MoveEnd() {
	selector_->DeSelectUnit();
}
