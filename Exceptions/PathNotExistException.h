#ifndef PATHNOTEXISTEXCEPTION_H
#define PATHNOTEXISTEXCEPTION_H

#include "BaseException.h" 

class PathNotExistException : public BaseException
{
public:
	PathNotExistException(std::string msg);
	PathNotExistException();	
};

#endif // PATHNOTEXISTEXCEPTION_H
