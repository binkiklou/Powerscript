#pragma once

#include <string>
#include <vector>

#include "Parser.h"

class Loop
{
public:
	Scope Def_Scope; // Scope inside
	void Run();
	std::vector<Parser::Statement> Statements;
};