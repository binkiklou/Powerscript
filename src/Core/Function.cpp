#include "Function.h"
#include "Powerscript.h"
#include "Log.h"

#include <iostream>

namespace Powerscript
{
	void Env::Call_Function(std::string name,std::vector<Argument> args)
	{
		//std::cout << "Call name is " << name << std::endl;
		if (name.compare("print") == 0)
		{
		//	std::cout << "Call i guess" << std::endl;
			if (args.at(0).Type == 0)
			{
			//	std::cout << "Type 0" << std::endl;
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
			//	std::cout << "Type 1" << std::endl;
				std::cout << args.at(0).CValue.PValue << std::endl;
			}
			else
			{
				std::cout << "Bro wtf" << std::endl;
			}
		}
	}
}