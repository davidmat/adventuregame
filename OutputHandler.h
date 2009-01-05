#ifndef OUTPUTHANDLER_H_
#define OUTPUTHANDLER_H_

#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdarg>

using namespace std;

class OutputHandler 
{
public:
      static OutputHandler* Instance();
      void print(string messageId, ...);
      string getMessage();
protected:
      OutputHandler();
      OutputHandler(const OutputHandler&);
      OutputHandler& operator= (const OutputHandler&);
private:
	  string message;
      static OutputHandler* pinstance;
};

#endif /*OutputHandler_H_*/
