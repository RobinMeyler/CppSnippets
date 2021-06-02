#pragma once

#include "ICommand.h"
#include <vector>
#include <list>
#include <algorithm>
#include <PlayerState.h>

class Player;

class MacroCommand 
{
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(PlayerState*);
	virtual void remove(PlayerState*);
	void execute(Player* p);
	virtual void undo();
	virtual void redo(Player* p);
	virtual void clearRedos();
	virtual void outputCommands();
	virtual void OutputRedoList();

private:
	std::list<PlayerState*> commands;
	std::list<PlayerState*> redos;
};

#include <Player.h>

