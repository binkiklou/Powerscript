#pragma once

#include <string>
#include <vector>

#include "Scope.h"

class Value
{
public:
	bool Undefined;
	std::string PValue; // Powerscript Value
	int GetType();
	int Type;
};

class Argument
{
public:
	Value CValue; // Current Value
	int Type; // 0 = variable, 1 = value
};

class Variable
{
public:
	std::string Name;
	Value CValue; // Current Value
	Scope VScope; // Variable Scope
};