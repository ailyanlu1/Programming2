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
// 	p01.cpp
//	List01.cpp ***
//	List01.h
//	p01make 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include "List01.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ARRAY OVERFLOW MESSAGE
struct OverflowException
{
	OverflowException()
	{
		cout << "Array is too small to hold input file size of array needs to be increased" << endl;
	}
};
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// CONSTRUCTOR AND DECONSTRUCTOR
List01::List01(char* input_file_name, char* output_file_name):input(input_file_name), output(output_file_name), size(100){
	my_list = new int[size];
};

List01::~List01(){
	delete[] my_list;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// READ OR SCAN METHOD, PUTS DATA INTO ARRAY
void List01::read(void){
	int i = 0;

	ifstream input_data (input); 

	while(true)
	{
		int s;
		input_data >> s;

		if(input_data.eof())
		{
			break;
		}

		if (i >= size - 1)
		{
			throw OverflowException();
		}

		my_list[i] = s;
		i++;
	}

	size = i; // SETS THE AMOUNT OF THE ARRAY USED

	input_data.close();
};
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// SORT ARRAY
void List01::sort(void){

	int eol = size - 1;

	while(eol >= 1)
	{
		int iom = 0;
		int i = 1;

		while(i <= eol)
		{
			if(my_list[i] > my_list[iom])
			{
				iom = i;
			}

			i++;
		}

		swap(eol, iom);
		eol --;
	}
};
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Swap numbers in array
void List01::swap(int a, int b){
	int c = my_list[a];
	my_list[a] = my_list[b];
	my_list[b] = c;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// METHOD USED TO WRITE DATA TO FILE
void List01::write(const char* message){

	o.open(output, ofstream::out | ofstream::app); // OUTPUT OR APPEND TO FILE
	o << message << endl;
	for(int i = 0; i <= size - 1; i++)
	{
		if(i % 10 == 0) o << endl;
		o << right << setw(5) << my_list[i] << " ";
	}

	o << endl;
	o << endl;
	o.close();
};
//------------------------------------------------------------------------------