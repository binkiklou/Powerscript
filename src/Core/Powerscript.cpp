#include "Powerscript.h"
#include "Function.h"
#include "../Console/Log.h"

#include <iostream>

namespace Powerscript
{
	/*
	==============
	Env Definition
	==============
	*/
	Env::Env()
	{

	}
	void Env::Run()
	{
		for (std::vector<Parser::Statement>::iterator s = this->StatementList.begin(); s != this->StatementList.end(); ++s)
		{
			Parser::Statement CStat; // Current Statement 
			CStat = *s;

			if (CStat.Executed != true)
			{
				if (CStat.Type == 1)
				{
					Log::Debug("Variable declaration");
					Env::Declare_Variable(CStat);
					s->Executed = true;
				}
				else if (CStat.Type == 2)
				{
					Log::Debug("Variable definition");
					Env::Define_Variable(CStat);
					s->Executed = true;
				}
				else if (CStat.Type == 5)
				{
					Log::Debug("Function call");
					Env::Call_Function(CStat.Stat_Name, CStat.Arguments);
					s->Executed = true;
				}
			}
		}
	}
	void Env::Add(std::string txt)
	{
		this->WordList = Parser::Disjoint(txt);
		Env::Analyze();
	}
}