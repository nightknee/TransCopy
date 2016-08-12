#ifndef FAILOPENEDFILEEXCEPTION_H
#define FAILOPENEDFILEEXCEPTION_H

#include "BaseException.h"

class OpenFileException : public BaseException
{
public:
	OpenFileException(std::string msg);
	OpenFileException();

};

#endif // FAILOPENEDFILEEXCEPTION_H
