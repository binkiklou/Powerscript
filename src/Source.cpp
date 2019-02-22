#include "Powerscript.h"
#include "Command.h"
#include "OS.h"
#include "Log.h"

#include <iostream>

void RunCommand(std::string txt) // That is some really bad code
{
	int Position = 0;
	std::string arg;

	bool DebugFlag = false;

	for (char &c : txt)
	{
		Position++;
		if (isspace(c))
		{
			
			arg.erase();
		}
		else
		{
			arg.append(1, c);

			if (arg.compare("Debug_Mode"))
			{
				DebugFlag = true;
			}
			if (DebugFlag == true && arg.compare("true") == 0)
			{
				Powerscript::Debug_Mode = true;
			}
			if (Position >= txt.length())
			{
				
				arg.erase();
			}
		}
	//	if (CPos >= txt.length())
	}
}

int main()
{
	std::cout << "PowerScript Interpreter Version "<< PSVersion << std::endl;
	std::cout << "Build of " << __TIMESTAMP__ << " for " << OsString << std::endl;
	std::cout << "Preprocessing commands(can only be done once by terminal):" << std::endl;

	Powerscript::Env Environement;

	std::string cmd;
	std::getline(std::cin, cmd);
	RunCommand(cmd);
	
	if (Powerscript::Debug_Mode == true)
	{
		Log::Debug("Activated");
	}

	while (true)
	{
		std::string input;
		std::cout << ">>>";
		std::getline(std::cin, input);
		Environement.Add(input);
		Environement.Run();
	}

	return 0;
}