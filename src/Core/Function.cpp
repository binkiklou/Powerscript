#include "../Core/Function.h"
#include "../Core/Powerscript.h"
#include "../Console/Log.h"

#include <iostream>

namespace Powerscript
{
	void Env::Call_Function(std::string name,std::vector<Argument> args)
	{
		if (name.compare("print") == 0)
		{
			if (args.at(0).Type == 0)
			{
				try
				{
					std::cout << this->ValueTable.at(Find_Variable(args.at(0).CValue.PValue)).CValue.PValue << std::endl;
				}
				catch (std::out_of_range)
				{
					Log::Debug("Argument of print, non existant");
				}
			}
			else if (args.at(0).Type == 1)
			{
				std::cout << args.at(0).CValue.PValue << std::endl;
			}
			else
			{
				std::cout << "Bro wtf" << std::endl;
			}
		}
	}
}