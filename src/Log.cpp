#include "Log.h"
#include "OS.h"
#include "Powerscript.h"

#include <iostream>

namespace Log
{
	void Debug(std::string txt)
	{
		if (Powerscript::Debug_Mode == true)
		{
			std::cout <<"Debug: "<< txt << std::endl;
			if (OsCode == 1)
			{
				HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hcon, 06);
				std::cout << "Debug: ";
				SetConsoleTextAttribute(hcon, 07);
				std::cout << txt << std::endl;
			}
		}
	}
	void Update(std::string txt)
	{
		if (OsCode == 1)
		{
			HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hcon, 01);
			std::cout << "Update: ";
			SetConsoleTextAttribute(hcon, 07);
			std::cout << txt << std::endl;
		}
	}
	void Error(std::string txt)
	{
		if (OsCode == 1)
		{
			HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hcon, 04);
			std::cout << "Error: ";
			SetConsoleTextAttribute(hcon, 07);
			std::cout << txt << std::endl;
		}
	}
}