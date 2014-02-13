//------------------------------------------------------------------------------
// Author: Mr. Lynn Barnett 
// Student ID: *20360727 
// E-Mail: barnettlynn@gmail.com 
// Course: CMSC 2613, Programming II 
// CRN: 21256, Spring, 2014 
// Project: p03 
// Due: February 14, 2014
// Account: tt044
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Files:
// 	p03.cpp ***
//	Stack03.h
//	Stack03.cpp
//  Scan03.h
//	Scan03.l
//	p03make 
//------------------------------------------------------------------------------

#include <cstdio>
#include <cstring>

#include "Stack03.h"
#include "Scan03.h"

//------------------------------------------------------------------------------
// EXCEPTION MESSAGES
struct CommandLineException
{
	CommandLineException(int max, int actual){
		cout << "Too many command line agruments." << endl;
		cout << "A Maximum of " << max << " arguments are permited" << endl;
		cout << actual  << " arguments were given" << endl;
	}
};

struct FileException
{
	FileException(const char* fn)
	{
		cout << "File " << fn << " could not be opened" << endl;
	}
};
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//POSTFIX MANAGER
void post_fix_mngr(FILE* input_stream, ofstream& output_stream) 
{	
	Scan L(input_stream);
	Stack03 post_fix_stack;
	int subtraction_holder;
	int division_holder;

	while(true){
		int t = L.Lex();
		if (t == 0) break;
		switch(t)
		{
			case INTLIT:
				post_fix_stack.Push(L.Intlit());
				break;
			case PLUS:
				post_fix_stack.Push(post_fix_stack.Pop() + post_fix_stack.Pop());
				break;
			case MINUS:
				subtraction_holder = post_fix_stack.Pop();
				post_fix_stack.Push(post_fix_stack.Pop() - subtraction_holder);
				break;
			case STAR:
				post_fix_stack.Push(post_fix_stack.Pop() * post_fix_stack.Pop());
				break;
			case SLASH:
				division_holder = post_fix_stack.Pop();
				post_fix_stack.Push(post_fix_stack.Pop()/division_holder);
				break;
			default:
			{
				break;
			}
		}
	 }

	post_fix_stack.Print(output_stream);
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//MAIN
int main(int argc, char* argv[])
{
	try
	{
		char input_file_name[255], output_file_name[255];

		switch(argc)
		{
			case 1:
				cout << "Please Enter The Input File Name" << endl;
				cout << ": ";
				cin >> input_file_name;
				cout << "Please Enter The Output File Name" << endl;
				cout << ": ";
				cin >> output_file_name;
				break;
			case 2:
				strcpy(input_file_name, argv[1]);
				cout << "Please Enter The Output File Name" << endl;
				cout << ": ";
				cin >> output_file_name;
				break;
			case 3:
				strcpy(input_file_name, argv[1]);
				strcpy(output_file_name, argv[2]);
				break;
			default:
				throw CommandLineException(2, argc-1);
				break;
		}

		FILE* input_stream = fopen(input_file_name,"r");
		if(!input_stream) throw FileException(input_file_name);
		ofstream output_stream (output_file_name);
		if(!output_stream) throw FileException(output_file_name);


		post_fix_mngr(input_stream, output_stream);


		output_stream.close();
		fclose(input_stream);
		

	} catch(...)
	{
		cout << "Something has gone wrong!!!" << endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}