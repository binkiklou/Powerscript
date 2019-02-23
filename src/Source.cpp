#include "Powerscript.h"
#include "Command.h"
#include "OS.h"
#include "Log.h"

#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "PowerScript Interpreter Version "<< PSVersion << std::endl;
	std::cout << "Build of " << __TIMESTAMP__ << " for " << OsString << std::endl;

	Powerscript::Env Environement;
	
	if (Powerscript::Debug_Mode == true)
	{
		Log::Debug("Activated");
	}

	while (true)
	{
		std::string input;
		std::cout << ">";
		std::getline(std::cin, input);
		Environement.Add(input);
		Environement.Run();
	}

	return 0;
}