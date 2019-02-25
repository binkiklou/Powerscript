#include "Variable.h"
#include "Powerscript.h"
#include "../Console/Log.h"

#include <iostream>

int Value::GetType()
{
	if (isdigit(this->PValue.at(0)))
	{
		return 1;
	}
	else if (this->PValue.compare("true") == 0)
	{
		return 2;
	}
	else if (this->PValue.compare("false") == 0)
	{
		return 2;
	}
	else if(Type != NULL)
	{
		return this->Type;
	}
	else
	{
		return 0;
	}
	return 0;
}

/*
========================================
POWERSCRIPT VARIABLE RELATED DECLARATION
========================================
*/
namespace Powerscript
{
	void Env::Declare_Variable(Parser::Statement Stat)
	{
	//	std::cout << "Variable declaration" << std::endl;
		Variable CVariable; // Current Variable

		if (Variable_Exist(Stat.Stat_Name))
		{
			Log::Error("Variable already exists");
		}
		else
		{
			CVariable.Name = Stat.Stat_Name;
			CVariable.CValue.Undefined = true;
			this->ValueTable.push_back(CVariable);

			this->ScopeList.push_back(Stat.Dec_Scope);
			Stat.Dec_Scope.id = static_cast<int>(this->ScopeList.size()) - 1;
		}
	}
	void Env::Define_Variable(Parser::Statement Stat)
	{
		Variable CVariable; // Current Variable
		int FVariable; // Found Variable
		FVariable = Find_Variable(Stat.Stat_Name);

		if (FVariable != -1)
		{
			if (Stat.Arguments.at(0).Type == 1)
			{
				this->ValueTable.at(FVariable).CValue.PValue = Stat.Arguments.at(0).CValue.PValue;
				CVariable = this->ValueTable.at(FVariable);
			}
			else if(Stat.Arguments.at(0).Type == 0)
			{
				try
				{
					this->ValueTable.at(FVariable).CValue.PValue = this->ValueTable.at(Find_Variable(Stat.Arguments.at(1).CValue.PValue)).CValue.PValue;
				}
				catch (std::out_of_range)
				{
					Log::Error("Variable doesn't exist");
				}
			}
		}
		else
		{
			Log::Error("Variable doesn't exist");
		}

 	//	std::cout << "Var is " << CVariable.Name << " and value is " << CVariable.Value << std::endl;
	}
	bool Env::Variable_Exist(std::string Name)
	{
		Variable Var;
		std::string Var_Name;
		bool Found = false;
		for (std::vector<Variable>::iterator v = this->ValueTable.begin(); v != this->ValueTable.end(); ++v)
		{
			Var = *v;
			Var_Name = Var.Name;
			if (Var_Name.compare(Name) == 0)
			{
			//	std::cout << "The variable exists" << std::endl;
				Found = true;
			}
		}
		if (Found == false)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	int Env::Find_Variable(std::string Name)
	{
		Variable Var;
		std::string Var_Name;
		bool Found = false;
		int pos = -1;
		for (std::vector<Variable>::iterator v = this->ValueTable.begin(); v != this->ValueTable.end(); ++v)
		{
			Var = *v;
			Var_Name = Var.Name;
			pos++;

			if (Var_Name.compare(Name) == 0)
			{
			//	std::cout << "The variable exists" << std::endl;
				Found = true;
				return pos;
			}
		}
		if (Found == false)
		{
			return -1;
		}
	}
}
