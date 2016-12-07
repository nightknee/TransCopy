#ifndef CMDOPTIONSPARSEREXCEPTION_H
#define CMDOPTIONSPARSEREXCEPTION_H 

#include "BaseException.h" 

class CmdOptionsParserException : public BaseException
{
public:
	CmdOptionsParserException(std::string msg);
	CmdOptionsParserException();
	~CmdOptionsParserException();

};

#endif // CMDOPTIONSPARSEREXCEPTION_H
