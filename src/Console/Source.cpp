#include "../Core/Powerscript.h"
#include "../Interface/Command.h"
#include "../Core/OS.h"
#include "../Console/Log.h"

#include <iostream>
#include <ctime>

int main()
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