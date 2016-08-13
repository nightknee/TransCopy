#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <string>

class BaseException : public std::exception{
public:
	BaseException(std::string msg);
	BaseException();
	virtual const char* what() const throw();
protected:
	std::string _msg;		
};

#endif // BASEEXCEPTION_H
