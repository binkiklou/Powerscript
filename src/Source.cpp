#include "Powerscript.h"
#include "Command.h"
#include "OS.h"
#include "Log.h"

#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "PowerScript Interpreter Version "<< PSVersion << std::endl;
	std::cout << "Build of " << __TIMESTAMP__ << " for " << OsString << std::endl;

	Powerscript::Env Environement;
	
	if (Powerscript::Debug_Mode == true)
	{
		Log::Debug("Activated");
	}

	while (true)
	{
		std::string input;
		std::cout << ">";
		std::getline(std::cin, input);
		Environement.Add(input);
		Environement.Run();
	}

	return 0;
}

/*
#include <fstream>
#include <iostream>

using namespace std;

int main ( int argc, char *argv[] )
{
  if ( argc != 2 ) // argc should be 2 for correct execution
	// We print argv[0] assuming it is the program name
	cout<<"usage: "<< argv[0] <<" <filename>\n";
  else {
	// We assume argv[1] is a filename to open
	ifstream the_file ( argv[1] );
	// Always check to see if file opening succeeded
	if ( !the_file.is_open() )
	  cout<<"Could not open file\n";
	else {
	  char x;
	  // the_file.get ( x ) returns false if the end of the file
	  //  is reached or an error occurs
	  while ( the_file.get ( x ) )
		cout<< x;
	}
	// the_file is closed implicitly here
  }
}
*/