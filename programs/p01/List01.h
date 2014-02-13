#ifndef List01_h
#define List01_h

#include <fstream>


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
//	List01.cpp
//	List01.h ***
//	p01make 
//------------------------------------------------------------------------------


#include <string>
class List01{
	int size;
	char* input;
	char* output;
	std::ofstream o;
	void swap(int a, int b);
	
public:
	List01(char* input_file_name, char* output_file_name);
	~List01();  // DESTRUCTOR, LOOK UP HOW THIS WORKS
	int* my_list;
	void read(void);
	void sort(void);
	void write(const char* message);
};
#endif