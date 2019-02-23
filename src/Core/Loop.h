#pragma once

#include <string>
#include <vector>

#include "Parser.h"

class Loop
{
public:
	int DecScope; // The scope where the function has been declared
	int DefScope; // The new scope that has been created
	void Run();
	std::vector<Parser::Statement> Statements;
};