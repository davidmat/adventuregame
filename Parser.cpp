#include "Parser.h"
#include <iostream>
#include <string>

Parser* Parser::pinstance = 0;// initialize pointer
Parser* Parser::Instance () 
{
    if (pinstance == 0)  // is it the first call?
    {  
      pinstance = new Parser; // create sole instance
    }
    return pinstance; // address of sole instance
}

Parser::Parser() 
{ 
    //... perform necessary instance initializations 
}

/*Parser::~Parser()
{
}*/

vector <string> Parser::getInput()
{
    vector <string> input;
    string word1, word2;
    char s[31];
    cout << "> ";     // print prompt
    cin.getline(s, 30);
    cin.clear();
    string string(s);
    int blanco = string.find_first_of(" ");
    if (blanco != -1)
    {
            word1= string.substr(0, blanco);
            word2 = string.substr(blanco+1, string.length());
    }
    else
    {
            word1 = string;
            word2 = "null";
    }
    input.push_back(word1);
    input.push_back(word2);

    return input;
}
