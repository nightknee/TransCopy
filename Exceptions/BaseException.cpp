#include "BaseException.h"
BaseException::BaseException(std::string msg){
	this->msg = msg;
}
BaseException::BaseException(){}

const char* BaseException::what() const throw(){
	return this->msg.c_str();
}