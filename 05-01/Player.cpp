#include "Player.h"
#include <Novice.h>

void MoveRightCommand::Execute(Player& player) {
	player.MoveRight();
}

void MoveLeftCommand::Execute(Player& player) {
	player.MoveLeft();
}

void Player::Initialize() {
	positionX_ = 100;
	positionY_ = 300;
	width_ = 50;
	height_ = 50;
}

void Player::Update() {
}

void Player::Draw() {
	Novice::DrawBox(positionX_, positionY_, width_, height_, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight() {
	positionX_ += 2;
}

void Player::MoveLeft() {
	positionX_ -= 2;
}
