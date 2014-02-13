#ifndef Scan03_h
#define Scan03_h 1
//--------------------------------------------------------------------
// File: Scan03.h                                                     
// Description:                                                       
// Recognizes integers and arithmetic operators for project 3 in      
// Programming II.                                                    
//--------------------------------------------------------------------
// Author: Thomas R. Turner                                           
// E-Mail: trturner.ucok.edu                                          
// Date:   September, 2002                                              
//--------------------------------------------------------------------
// Copyright September, 2002 by Thomas R. Turner
// Do not reproduce without permission from Thomas R. Turner.
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// Standard C and C++ include files                                        
//--------------------------------------------------------------------
#include <cstdio>
#include <fstream>
#include <iostream>
using namespace std;
//--------------------------------------------------------------------
//Token code definitions
//--------------------------------------------------------------------
#define INTLIT 1
#define PLUS   2
#define MINUS  3
#define STAR   4
#define SLASH  5
//--------------------------------------------------------------------
//Function: yylex                                                     
//Function yylex is the Scanner.  Function yylex returns an integer   
//token code as defined above or 0 if end-of-file has been     
//reached.                                                            
//--------------------------------------------------------------------
#ifdef __cplusplus
extern "C" 
#endif
int yylex (void);
//--------------------------------------------------------------------
//Class Scan defines the attributes of a Scanner
//--------------------------------------------------------------------
class Scan {
  int tokencode;                 //Code for the most recent token found
public:
  Scan(FILE* i);                 //Redirect the input source from the 
                                 //keyboard to input file i.
  int Lex(void);                 //Call the scanner yylex and return the code
                                 //found by yylex
  int FetchTokenCode(void);      //Return the code of the most recent token
  void StoreTokenCode(int T);    //Store the token code.
  char* FetchSpelling(void);     //Return the spelling of the most recent
                                 //token
  int Intlit(void);              //Return the most recent integer literal
};
#endif