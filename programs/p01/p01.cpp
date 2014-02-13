//------------------------------------------------------------------------------
// Author: Mr. Lynn Barnett 
// Student ID: *20360727 
// E-Mail: barnettlynn@gmail.com 
// Course: CMSC 2613, Programming II 
// CRN: 21256, Spring, 2014 
// Project: p01 
// Due: January 24, 2014
// Account: tt044
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Files:
// 	p01.cpp ***
//	List01.cpp
//	List01.h
//	p01make 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "List01.h"

using namespace std;
//------------------------------------------------------------------------------


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

//------------------------------------------------------------------------------
// TEST IF INPUT FILES CAN BE USED
		ifstream i (input_file_name);
		if(!i) throw FileException(input_file_name);
		ofstream o (output_file_name);
		if(!o) throw FileException(output_file_name);

		o.close();
		i.close();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// MAIN LIST OPERATIONS		
		List01 main_list(input_file_name, output_file_name);
		main_list.read();
		main_list.write("Unsorted List: ");
		main_list.sort();
		main_list.write("Sorted List: ");
//------------------------------------------------------------------------------


	} catch(...)
	{
		cout << "Something has gone wrong!!!" << endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}
