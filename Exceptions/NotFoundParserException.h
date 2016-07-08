#ifndef NOTFOUNDPARSEREXCEPTION_H
#define NOTFOUNDPARSEREXCEPTION_H

#include "BaseException.h" 

class NotFoundParserException : public BaseException
{
public:
	virtual const char* what() const throw(){
		return "Not found parser for this extension file.";
	}

};

#endif // NOTFOUNDPARSEREXCEPTION_H
