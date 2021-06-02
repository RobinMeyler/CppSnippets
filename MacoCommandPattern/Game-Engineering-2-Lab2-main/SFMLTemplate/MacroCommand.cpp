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

void MacroCommand::add(Command* c)
{
	commands.push_back(c);
} 

void MacroCommand::remove(Command* c)
{
	commands.remove(c);
}

void MacroCommand::execute()
{
	for (auto &com : commands)
	{
		com->execute();
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

void MacroCommand::redo()
{
	if (redos.size() > 0)
	{
		std::cout << "== Redo last item ==" << std::endl;
		auto last = redos.end();		// Iterator 1 past the last
		last--;							// Last entry
		commands.push_back(*last);
		redos.pop_back();
	}
}

void MacroCommand::clearRedos()
{
	if (redos.size() > 0)
	{
		redos.clear();
	}
}

void MacroCommand::outputCommands()
{
	for (auto& comms : commands)
	{
		comms->execute();
	}
}

void MacroCommand::OutputRedoList()
{
	for (auto& comms : redos)
	{
		comms->execute();
	}
}
