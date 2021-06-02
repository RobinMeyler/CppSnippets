#pragma once

#include "ICommand.h"
#include"CommandClasses.h"
#include "MacroCommand.h"

enum class INPUTS{
	INPUT1 = 0,
	INPUT2 = 1,
	INPUT3 = 2,
	INPUT4 = 3
};


class InputHandler
{
public:

	InputHandler() {
		Input1 = new RunCommand();
		Input2 = new WalkCommand();
		Input3 = new AttackCommand();
		Input4 = new CrouchCommand();
	}

	~InputHandler()
	{
		delete Input1;
		delete Input2;
		delete Input3;
		delete Input4;
	}
	void handleInput(INPUTS t_input)
	{
		switch (t_input)
		{
		case INPUTS::INPUT1:
			Input1->execute();
			m_inputHistory.add(Input1);
			break;
		case INPUTS::INPUT2:
			Input2->execute();
			m_inputHistory.add(Input2);
			break;
		case INPUTS::INPUT3:
			Input3->execute();
			m_inputHistory.add(Input3);
			break;
		case INPUTS::INPUT4:
			Input4->execute();
			m_inputHistory.add(Input4);
			break;
		default:
			break;
		}
		m_inputHistory.clearRedos();
	};

	void Undo()
	{
		m_inputHistory.undo();
	};
	void Redo() 
	{
		m_inputHistory.redo();
	};

	void OutputMacro()
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
	Command* Input1;
	Command* Input2;
	Command* Input3;
	Command* Input4;
	MacroCommand m_inputHistory;
};