#pragma once
#include "IStageSceneCommand.h"
#include "Selector.h"

class SelectorMoveCommand : public IStageSceneCommand {
public:
	SelectorMoveCommand(Selector* selector, int x, int y);
	void Execute() override;
	void Undo() override;
private:
	Selector* selector_;
	int x_;
	int y_;
};

class SelectUnitCommand : public IStageSceneCommand {
public:
	SelectUnitCommand(Selector* selector);
	void Execute() override;
	void Undo() override;
private:
	Selector* selector_;
};

class UnitMoveCommand : public IStageSceneCommand {
public:
	UnitMoveCommand(Unit* unit, int x, int y);
	void Execute() override;
	void Undo() override;
private:
	Unit* unit_;
	int x_;
	int y_;
};

class UnitMoveEndCommand : public IStageSceneCommand {
public:
	UnitMoveEndCommand(Unit* unit, Selector* selector);
	void Execute() override;
	void Undo() override;
private:
	Unit* unit_;
	Selector* selector_;
};

class CreateUnitCommand : public IStageSceneCommand {
public:
	CreateUnitCommand(Selector* selector);
	void Execute() override;
	void Undo() override;
private:
	Selector* selector_;
	int createdUnitID_;
};
