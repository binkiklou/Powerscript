#include "../Core/Parser.h"
#include "../Core/Powerscript.h"
#include "../Console/Log.h"

#include <iostream>

namespace Parser
{
	std::vector<std::string> Disjoint(std::string txt)
	{
		int CPos = 0; // Position of the C variable
		std::vector<std::string> Result;
		std::string CWord; // Current Word
		for (char &c : txt)
		{
			CPos++;
			if (isspace(c))
			{
				if (CWord.compare("") != 0)
				{
					Result.push_back(CWord);
					CWord.erase();
				}
			}
			else
			{
				if (c == '=' || c == '<' || c == '>' || c == '(' || c == ')' || c == '.' || c == '"')
				{
					if (CWord.compare("") != 0)
					{
						Result.push_back(CWord);
						CWord.clear();
					}
					CWord.append(1, c);
					Result.push_back(CWord);
					CWord.clear();
				}
				else
				{
					CWord.append(1, c);
				}

				if (CPos >= txt.length())
				{
					Result.push_back(CWord);
					CWord.erase();
				}
			}
		}
		return Result;
	}
	/*
	====================
	STATEMENT DEFINITION
	====================
	*/

	/*void Statement::Clear()
	{
		int NoInt;
		std::string NoString;
		Type = NoInt;
		Def_Scope = NoInt;
		Dec_Scope = NoInt;
		Var_Value = NoString;
		Stat_Name = NoString;
		Func_Arguments = NoString;
	}*/
}

namespace Powerscript
{
	/*
	===================
	ENV DECLARATION TOO
	===================
	*/
	void Env::Analyze()
	{
		int WPos = -1;

		Scope CScope; // Current Scope
		CScope.x = 0;
		CScope.y = 0;
		CScope.p = 0;

		//std::vector<std::string> CList; // Current Word List
		std::string Word;
		std::string Fix;
		Fix.append(1, '"');

		bool isString = false;

		for (std::vector<std::string>::iterator w = this->WordList.begin(); w != this->WordList.end(); ++w)
		{
			Parser::Statement CStatement; // Current Statement
			CStatement.Type = 0;
			WPos++;
			Word = *w;
		//	CList.push_back(Word);
		//	std::cout << "Word is " << Word << std::endl;
			if (Word.compare(Fix) == 0)
			{
				if (isString == false)
				{
					Log::Debug("String mode on");
					isString = true;
				}
				else
				{
					Log::Debug("String mode off");
					isString = false;
				}
			}
			if (Word.compare("global") == 0)
			{
				std::string Def_Word; // Definition  Word
				std::string Name;
				CStatement.Def_Scope = CScope;

				//std::cout << "WPos is " << WordList.at(WPos) << std::endl;

				try
				{
					Def_Word = this->WordList.at(WPos + 2); // Potential declaration keyword
				}
				catch(std::out_of_range)
				{
					Log::Debug("Error handled, declaration word out of range");
				}
				try
				{
					Name = this->WordList.at(WPos + 1);
				}
				catch (std::out_of_range)
				{
					Log::Debug("Error handled, name out of range");
				}

			/*	if (Def_Word.compare("=") == 0)
				{

				}
				else*/ 
				if (Def_Word.compare("=") != 0) // Statemenet is dec
				{
					CStatement.Type = 1;
					CStatement.Stat_Name = Name;
					CStatement.Dec_Scope = CScope;
					this->StatementList.push_back(CStatement);
				}
			}
			if (Word.compare("=") == 0)
			{
			//	std::cout << "Equal sign" << std::endl;
				std::string NextWord;
				std::string Name;
				std::string Value;

				try
				{
					NextWord = this->WordList.at(WPos + 1);
					Name = this->WordList.at(WPos - 1);
				}
				catch (std::out_of_range)
				{
					std::cout << "Execption handled: Word Position is out of range" << std::endl;
					std::cout << "Code exit" << std::endl;
					break;
				}

			//	if (NextWord.compare("=") == 0) // Might be a if statement
			//	{
			//	}
			//	else
			//	{
					int LPos = 0;
					bool VString = false; // Value String
					bool VInt = false;
					bool VBool = false;
					bool VName = false;
//					std::string CValue; // Current Value

					Argument arg;

					for (auto const& word : WordList) // That is still really inneficient
					{
						LPos++;
						if (LPos >= WPos)
						{
							//	std::cout << "Words are " << word << std::endl;
							if (VString == true)
							{
								Log::Debug("Argument is String");
								if (word.compare(Fix) == 0)
								{
									Log::Debug("String argument break");
									break;
								}
								else if (word.compare(Fix) != 0)
								{
									std::string owo = word;
									owo.append(1, ' ');
									arg.CValue.Type = 3;
									arg.CValue.PValue.append(owo);
								}
							}
							if (word.compare(Fix) == 0)
							{
								Log::Debug("Start Arg String");
								VString = true;
							}
						}
					}

					CStatement.Type = 2;
					CStatement.Stat_Name = Name;

					if (VString == false)
					{
						arg.CValue.PValue = NextWord;
					}

					if (arg.CValue.GetType() == 1) // Int
					{
						VInt = true;
						arg.CValue.Type = 1;
						arg.CValue.PValue = NextWord;
					}
					else
					{
						VInt = false;
					}

					if (arg.CValue.GetType() == 2)
					{
						VBool = true;
						arg.CValue.Type = 2;
						Log::Debug("Is Boolean");
					}
					else
					{
						VBool = false;
					}

					if (VString == false && VInt == false && VBool == false)
					{
						Log::Debug("Value is variable name");

						arg.Type = 0;
						CStatement.Arguments.push_back(arg);

						Argument SArg; // Second Variable
						SArg.CValue.PValue = NextWord;
						SArg.Type = 0;
						CStatement.Arguments.push_back(SArg);
					}
					else
					{
						arg.Type = 1;
						CStatement.Arguments.push_back(arg);
					}
					this->StatementList.push_back(CStatement);
			//	}
			}
			if (Word.compare("(") == 0)
			{
				std::string D_Word; // Declaration Word

				try
				{
					D_Word = this->WordList.at(WPos - 2);
				}
				catch (std::out_of_range)
				{
					Log::Debug("Handled Exception: Declaration word, would be out of range");
				}

				if (D_Word.compare("function") == 0)
				{
					if (!isString)
					{
						//..
						std::cout << "Function" << std::endl;
					}
					else
					{
						// Wtf why would anyone do that
					}
				}
				else if(!isString)
				{
					bool AString = false; // Argument is String ?
					std::string AValue;
					int LPos = 0; // Local Position

					// Check Argument Type && Number
					// Wow that is inneficient as hell but the classic loop wouldn't work "no conversion from unsingned int"
					for (auto const& word : WordList)
					{
						LPos++;
						if (LPos >= WPos)
						{
							//	std::cout << "Words are " << word << std::endl;
							if (AString == true)
							{
								Log::Debug("Argument is String");
								if (word.compare(Fix) == 0)
								{
									Log::Debug("String argument break");
									break;
								}
								else if (word.compare(Fix) != 0)
								{
									std::string owo = word;
									owo.append(1, ' ');
									AValue.append(owo);
								}
							}
							if (word.compare(Fix) == 0)
							{
								Log::Debug("Start Arg String");
								AString = true;
							}
						}
					}

					Value Temp;
					Argument Carg; // Current Argument

					CStatement.Type = 5;
					CStatement.Stat_Name = this->WordList.at(WPos - 1);

					if (AString == false)
					{
						Temp.PValue = this->WordList.at(WPos + 1);
						Carg.CValue.PValue = Temp.PValue;
						Carg.Type = 0;
					}
					else
					{
						Carg.CValue.PValue = AValue;
						Carg.Type = 1;
					}

					CStatement.Arguments.push_back(Carg);
				//	std::cout << "CArg value is " << Carg.CValue.PValue << std::endl;

					this->StatementList.push_back(CStatement);
				}
			}
		}
	}
}
