#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <vector>

using namespace std;

class Parser 
{
public:
      static Parser* Instance();
      vector <string> getInput();
protected:
      Parser();
      Parser(const Parser&);
      Parser& operator= (const Parser&);
private:
      static Parser* pinstance;
};

#endif /*PARSER_H_*/
