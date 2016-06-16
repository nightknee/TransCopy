#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <string>

class BaseException{
public:
	BaseException(){
	this->exceptionName = "BaseException";		
}
BaseException(std::string msg): BaseException(){
	this->setMessage(msg);
}
std::string getMessage(){
	return this->message;
}

std::string getExceptionName(){
	return this->exceptionName;
}
	
void setMessage(std::string msg){
	this->message = msg;
}
	
protected:
	std::string message;
	std::string exceptionName;	
};


#endif // BASEEXCEPTION_H
