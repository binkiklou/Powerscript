#pragma once
#include "Scope.h"

#include <string>
#include <vector>

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
//	Variable();
	std::string Name;
	Value CValue; // Current Value
	Scope VScope;
};