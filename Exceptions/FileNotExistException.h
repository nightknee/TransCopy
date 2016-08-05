#ifndef FILENOTEXISTEXCEPTION_H
#define FILENOTEXISTEXCEPTION_H

#include "BaseException.h" 

class FileNotExistException : public BaseException
{
public:
	FileNotExistException(std::string msg);
	FileNotExistException();	
};

#endif // FILENOTEXISTEXCEPTION_H
