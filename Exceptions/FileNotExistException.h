#ifndef FILENOTEXISTEXCEPTION_H
#define FILENOTEXISTEXCEPTION_H

#include "BaseException.h" 

class FileNotExistException : public BaseException
{
public:
	virtual const char* what() const throw(){
		return "Set file doesn't exist.";
	}

};

#endif // FILENOTEXISTEXCEPTION_H
