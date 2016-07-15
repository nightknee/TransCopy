#ifndef PATHNOTEXISTEXCEPTION_H
#define PATHNOTEXISTEXCEPTION_H

#include "BaseException.h" 

class PathNotExistException : public BaseException
{
public:
	virtual const char* what() const throw(){
		return "Path doesn't exist.";
	}

};

#endif // PATHNOTEXISTEXCEPTION_H
