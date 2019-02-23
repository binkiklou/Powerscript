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

		void Define_Variable(Parser::Statement);
		void Declare_Variable(Parser::Statement);
		bool Variable_Exist(std::string);
		int Find_Variable(std::string);

		void Call_Function(std::string,std::vector<Argument>);
	//	Variable& Find_Variable(std::string);
	private:
		std::vector<std::string> WordList;
		std::vector<Parser::Statement> StatementList;
		std::vector<Variable> ValueTable;
		std::vector<Function> FunctionTable;
	};
	static bool Debug_Mode;
}