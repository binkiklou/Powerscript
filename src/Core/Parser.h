#pragma once

#include "../Core/Variable.h"

#include <string>
#include <vector>

namespace Parser
{
	std::vector<std::string> Disjoint(std::string);
	class Statement 
	{
	public:
		int Type;
		Scope Dec_Scope; // The scope where the statement has been declared
		Scope Def_Scope; //  If it's a if or function statement it is the new scope
		bool Executed;
		std::string Stat_Name;
		std::vector<Argument> Arguments;
	};
}