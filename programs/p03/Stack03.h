#ifndef Stack03_h
#define Stack03_h
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
// 	p03.cpp
//	Stack03.h ***
//	Stack03.cpp
//  Scan03.h
//	Scan03.l
//	p03make 
//------------------------------------------------------------------------------

#include <fstream> // for ofstream

class Stack03{
	struct Element{
		Element* prev;
		int value;
		Element(Element*p, int v):prev(p), value(v){}
	};
	Element* tos;

	void Kill(Element* e);

public:
	Stack03(void);
	~Stack03(void);
	bool isFull(void);
	bool isEmpty(void);
	void Push(int t);
	int Pop(void);
	void Print(std::ofstream& output_stream);
};

#endif