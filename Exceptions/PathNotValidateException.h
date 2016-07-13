#ifndef PATHNOTVALIDATEEXCEPTION_H
#define PATHNOTVALIDATEEXCEPTION_H

#include "BaseException.h" 

class PathNotValidateException : public BaseException
{
public:
	virtual const char* what() const throw(){
		return "Fail validate path destination.";
	}

};

#endif // PATHNOTVALIDATEEXCEPTION_H
