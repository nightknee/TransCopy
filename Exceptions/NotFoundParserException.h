#ifndef NOTFOUNDPARSEREXCEPTION_H
#define NOTFOUNDPARSEREXCEPTION_H

#include "BaseException.h" 

class NotFoundParserException : public BaseException
{
public:
	NotFoundParserException(std::string msg);
	NotFoundParserException();
};

#endif // NOTFOUNDPARSEREXCEPTION_H
