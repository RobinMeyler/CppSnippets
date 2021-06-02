#pragma once

#include "MacroCommand.h"
#include <PlayerState.h>
#include "Events.h"
#include "ICommand.h"


class InputHandler
{
public:

	InputHandler() 
	{
	}

	~InputHandler()
	{
	}

	void addHistory(PlayerState* command)
	{
		PlayerState* stateCopy = command;
		m_inputHistory.add(stateCopy);
		m_inputHistory.clearRedos();
	}
	
	void Undo()
	{
		m_inputHistory.undo();
	};
	void Redo(Player* p)
	{
		m_inputHistory.redo(p);
	};

	void OutputMacro( )
	{
		std::cout << "" << std::endl;
		std::cout << "Commands in buffer:" << std::endl;
		m_inputHistory.outputCommands();
		std::cout << "" << std::endl;
		std::cout << "Commands in RedoList:" << std::endl;
		m_inputHistory.OutputRedoList();
		std::cout << "" << std::endl;
	};
private:
	MacroCommand m_inputHistory;
};