#ifndef NOTFOUNDPARSEREXCEPTION_H
#define NOTFOUNDPARSEREXCEPTION_H

#include "BaseException.h" 

class NotFoundParserException : public BaseException
{
public:
	NotFoundParserException()
	{
		this->exceptionName = "NotFoundParserException";
	}
	NotFoundParserException(std::string msg) : NotFoundParserException()
	{
		this->setMessage(msg);
	}

};

#endif // NOTFOUNDPARSEREXCEPTION_H
