#pragma once

#include "Parser.h"
#include "Function.h"
//No Loop.h

#define PSVersion "0.1.0"

namespace Powerscript
{
	class Env
	{
	public:
		Env();
		void Run();
		void Add(std::string);
		void Analyze();

		int Find_Variable(std::string);

		void Define_Variable(Parser::Statement);
		void Declare_Variable(Parser::Statement);
		void Call_Function(std::string,std::vector<Argument>);

		bool Variable_Exist(std::string);
		bool Scope_Reach(Scope);

		Scope Scope_By_Id(int);
	private:
		std::vector<std::string> WordList;
		std::vector<Parser::Statement> StatementList;
		std::vector<Variable> ValueTable;
		std::vector<Function> FunctionTable;
		std::vector<Scope> ScopeList; // Parent
	};
	static bool Debug_Mode;
}