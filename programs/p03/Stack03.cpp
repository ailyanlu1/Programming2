//------------------------------------------------------------------------
// Author: Mr. Lynn Barnett 
// Student ID: *20360727 
// E-Mail: barnettlynn@gmail.com 
// Course: CMSC 2613, Programming II 
// CRN: 21256, Spring, 2014 
// Project: p03 
// Due: February 14, 2014
// Account: tt044
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Files:
// 	p03.cpp
//	Stack03.h
//	Stack03.cpp ***
//  Scan03.h
//	Scan03.l
//	p03make 
//------------------------------------------------------------------------

//------------------------------------------------------------------------
//INCLUDES
#include "Stack03.h"
#include <iostream>
//------------------------------------------------------------------------

//------------------------------------------------------------------------
//EXCEPTIONS
struct StackException {
	StackException(const char* m)
	{
		std::cout << std::endl;
		std::cout << "I am the Stack and I am" << m << ".";
		std::cout << std::endl;
	}
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// CONSTRUCTOR AND DESTRUCTOR
Stack03::Stack03():tos(0){};

Stack03::~Stack03()
{
	Kill(tos);
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
//IS FULL, AND IS EMPTY METHODS
bool Stack03::isFull(void)
{
	return false;
};

bool Stack03::isEmpty(void)
{
	return tos == 0;
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
//PUSH AND POP
void Stack03::Push(int t)
{
		if(isFull()) throw StackException("full");
		Element* n = new Element(tos, t);
		tos=n;
};

int Stack03::Pop(void)
{
	if(isEmpty()) throw StackException("empty");
	Element* p = tos;
	int t = p->value;
	tos = p->prev;
	delete p;
	return t;
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
//PRINT
void Stack03::Print(std::ofstream& output_stream)
{
	Element* iterator = tos;
	int i = 0;

	while(true)
	{
		if(i == 0)
		{
			output_stream << "Stack[tos]=" << iterator->value << std::endl;
		} else{
			output_stream << "Stack[tos-" << i << "]=" << iterator->value << std::endl;
		}
		iterator = iterator->prev;
		if(iterator == 0) break;
		i++;
	}
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
//KILL, CALLED BY THE DESTRUCTOR TO DELETE ALL THE ELEMENTS OF THE LIST
void Stack03::Kill(Element* e)
{
	while(e)
	{
		Element* p = e;
		e = e->prev;
		delete p;
	}
};
//------------------------------------------------------------------------




