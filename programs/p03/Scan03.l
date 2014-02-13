%{
//--------------------------------------------------------------------
// File: Scan03.l                                                     
// Description:                                                       
// Contains the most elementary example use of lex for the purpose of 
// building a scanner.                                                
//-------------------------------------------------------------------
// Author: Thomas R. Turner                                           
// E-Mail: trturner@ucok.edu                                          
// Date:   September, 2002
//--------------------------------------------------------------------
//Copyright September, 2002 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// Standard C and C++ Library Include Files                                     
//--------------------------------------------------------------------
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//--------------------------------------------------------------------
// Application Includes                                               
//--------------------------------------------------------------------
#include "Scan03.h"
//--------------------------------------------------------------------
//Function prototypes
//--------------------------------------------------------------------
int TokenMgr(int T);
//--------------------------------------------------------------------
//Global Variables                                                    
//--------------------------------------------------------------------
%}
%%
[ \t\n]+                           ;
[+-]?[0-9]+                        {   
                                        return(TokenMgr(INTLIT));
                                   }
"+"                                {    
                                        return(TokenMgr(PLUS));
                                   }
"-"                                {    
                                        return(TokenMgr(MINUS));
                                   }
"*"                                {    
                                        return(TokenMgr(STAR));
                                   }
"/"                                {    
                                        return(TokenMgr(SLASH));
                                   }
%%
//--------------------------------------------------------------------
int TokenMgr(int T)
{  return T;
}
//--------------------------------------------------------------------
//Class Scan implementation
//--------------------------------------------------------------------
//Constructor Scan is used to redirect the input file stream from the
//keyboard to input file stream i.
//--------------------------------------------------------------------
Scan::Scan(FILE* i)
{  yyin=i;
}
//--------------------------------------------------------------------
//Function Lex calls yylex
//--------------------------------------------------------------------
int Scan::Lex(void)
{  return tokencode=yylex();
}
//--------------------------------------------------------------------
//Function FetchSpelling returns a pointer to the spelling of the most
//recent token.
//--------------------------------------------------------------------
char* Scan::FetchSpelling(void)
{  return (char*)yytext;
} 
//--------------------------------------------------------------------
//Function FetchTokenCode returns the code of the most recent token 
//--------------------------------------------------------------------
int Scan::FetchTokenCode(void)
{  return tokencode;
}
//--------------------------------------------------------------------
//Function StoreTokenCode records the most recent token code
//--------------------------------------------------------------------
void Scan::StoreTokenCode(int T)
{  tokencode=T;
}
//--------------------------------------------------------------------
//Function Intlit returns the most recent integer literal
//--------------------------------------------------------------------
int Scan::Intlit(void)
{   int i;
    sscanf(yytext,"%d",&i);
    return i;
}
//-----------------------End of Lex Definition------------------------