#include "SelectorCommand.h"

SelectorMoveCommand::SelectorMoveCommand(Selector* selector, int x, int y) {
	selector_ = selector;
	x_ = x;
	y_ = y;
}

void SelectorMoveCommand::Execute() {
	selector_->Move(x_, y_);
}

void SelectorMoveCommand::Undo() {
	selector_->Move(-x_, -y_);
}

SelectUnitCommand::SelectUnitCommand(Selector* selector) {
	selector_ = selector;
}

void SelectUnitCommand::Execute() {
	selector_->SelectUnit();
}

void SelectUnitCommand::Undo() {
	selector_->DeSelectUnit();
}

UnitMoveCommand::UnitMoveCommand(Unit* unit, int x, int y) {
	unit_ = unit;
	x_ = x;
	y_ = y;
}

void UnitMoveCommand::Execute() {
	unit_->Move(x_, y_);
}

void UnitMoveCommand::Undo() {
	unit_->Move(-x_, -y_);
}

UnitMoveEndCommand::UnitMoveEndCommand(Unit* unit, Selector* selector) {
	unit_ = unit;
	selector_ = selector;
}

void UnitMoveEndCommand::Execute() {
	unit_->MoveEnd();
}

void UnitMoveEndCommand::Undo() {
	selector_->SelectUnit();
}

CreateUnitCommand::CreateUnitCommand(Selector* selector) {
	selector_ = selector;
}

void CreateUnitCommand::Execute() {
	createdUnitID_ = selector_->AddUnit();
}

void CreateUnitCommand::Undo() {

}
