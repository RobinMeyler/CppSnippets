#include "MacroCommand.h"
#include <iostream>

MacroCommand::MacroCommand()
{
}

MacroCommand::~MacroCommand()
{
	for (auto& comms : commands)
	{
		delete comms;
	}
	for (auto& reds : redos)
	{
		delete reds;
	}
	commands.clear();
	redos.clear();
}

void MacroCommand::add(PlayerState* c)
{
	commands.push_back(c);
} 

void MacroCommand::remove(PlayerState* c)
{
	commands.remove(c);
}

void MacroCommand::execute(Player* p)
{
	for (auto &com : commands)
	{
		com->enter(*p);
	}
}

void MacroCommand::undo()
{
	if (commands.size() > 0)
	{
		std::cout << "== Undo last item ==" << std::endl;
		auto last = commands.end();	// Iterator 1 past the last
		last--;						// Last entry
		redos.push_back(*last);
		commands.pop_back();
	}
}

void MacroCommand::redo(Player* p)
{
	if (redos.size() > 0)
	{
		std::cout << "== Redo last item ==" << std::endl;
		auto last = redos.end();		// Iterator 1 past the last
		last--;							// Last entry
		commands.push_back(*last);
		p->getPlayerState()->exit(*p);
		p->setPlayerState(*last);
		(*last)->enter(*p);
		redos.pop_back();
	}
}

void MacroCommand::clearRedos()
{
	if (redos.size() > 0)
	{
		for (auto& red : redos)
		{
			delete red;
		}
		redos.clear();
	}
}

void MacroCommand::outputCommands()
{
	for (auto& comms : commands)
	{
		comms->name();
	}
}

void MacroCommand::OutputRedoList()
{
	for (auto& comms : redos)
	{
		comms->name();
	}
}
