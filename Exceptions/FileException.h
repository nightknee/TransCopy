#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H

#include "BaseException.h" 

class FileException : public BaseException
{
public:
	FileException(std::string msg);
	FileException();	
};

#endif // FILEEXCEPTION_H
