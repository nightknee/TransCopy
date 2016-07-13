#ifndef FILETOPARSENOTVALIDATEEXCEPTION_H
#define FILETOPARSENOTVALIDATEEXCEPTION_H

#include "BaseException.h" 

class FileToParseNotValidateException : public BaseException
{
public:
	virtual const char* what() const throw(){
		return "Fail validate path destination.";
	}

};

#endif // FILETOPARSENOTVALIDATEEXCEPTION_H
