#pragma once

#include "../Core/Variable.h"

#include <string>
#include <vector>

namespace Parser
{
	std::vector<std::string> Disjoint(std::string);
//	void Analyze(std::vector<std::string>);
	class Statement 
	{
	public:
		int Type;
		Scope Def_Scope; // The scope where the statement has been defined
		Scope Dec_Scope; //  If it's a if or function statement it is the new scope
		bool Executed;
		std::string Stat_Name;
		std::vector<Argument> Arguments;
	};
}