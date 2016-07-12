#ifndef NOTFOUNDPARSEREXCEPTION_H
#define NOTFOUNDPARSEREXCEPTION_H

#include "BaseException.h" 

class FileNotExistException : public BaseException
{
public:
	virtual const char* what() const throw(){
		return "Set file doesn't exist.";
	}

};

#endif // NOTFOUNDPARSEREXCEPTION_H
