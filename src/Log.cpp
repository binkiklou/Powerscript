#include "Log.h"
#include "OS.h"
#include "Powerscript.h"

#include <iostream>

/*
Linux terminal stuff:

Reset \x1B[0m
Bold \x1B[1m
Underline \x1B[4m

Red \x1B[31m
Green \x1B[32m
Yellow \x1B[33m
Blue \x1B[34m
Magenta \x1B[35m
Cyan \x1B[36m
White \x1B[37m
*/

namespace Log
{
	void Debug(std::string txt)
	{
		if (Powerscript::Debug_Mode == true)
		{
			std::cout <<"Debug: "<< txt << std::endl;
#if OsCode == 1 // Windows
				HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hcon, 06);
				std::cout << "Debug: ";
				SetConsoleTextAttribute(hcon, 07);
				std::cout << txt << std::endl;
#elif OsCode == 3 // Linux
			std::cout << "\x1B[33m" << "Debug:" << "\x1B[0m" << txt << std::endl;
#endif
		}
	}
	void Update(std::string txt)
	{
#if OsCode == 1 // Windows
			HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hcon, 01);
			std::cout << "Update: ";
			SetConsoleTextAttribute(hcon, 07);
			std::cout << txt << std::endl;
#elif OsCode == 3 // Linux
		std::cout << "\x1B[34m" << "Update:" << "\x1B[0m" << txt << std::endl;
#endif
	}
	void Error(std::string txt)
	{
#if OsCode == 1 // Windows
			HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hcon, 04);
			std::cout << "Error: ";
			SetConsoleTextAttribute(hcon, 07);
			std::cout << txt << std::endl;
#elif OsCode == 3 // Linux
		std::cout << "\x1B[31m" << "Error:" << "\x1B[0m" << txt << std::endl;
#endif
	}
}