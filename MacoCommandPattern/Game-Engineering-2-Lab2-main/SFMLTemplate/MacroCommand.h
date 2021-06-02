#pragma once

#include "ICommand.h"
#include <vector>
#include <list>>
#include <algorithm>

class MacroCommand : public Command
{
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute() override;
	virtual void undo();
	virtual void redo();
	virtual void clearRedos();
	virtual void outputCommands();
	virtual void OutputRedoList();

private:
	std::list<Command*> commands;
	std::list<Command*> redos;
};

