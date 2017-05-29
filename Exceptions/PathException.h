#ifndef PATHNOTEXISTEXCEPTION_H
#define PATHNOTEXISTEXCEPTION_H

#include "BaseException.h" 

class PathException : public BaseException
{
public:
	PathException(std::string msg);
	PathException();	
};

#endif // PATHNOTEXISTEXCEPTION_H
