#include "BaseException.h"
BaseException::BaseException(std::string msg){
	this->_msg = msg;
}
BaseException::BaseException(){}

const char* BaseException::what() const throw(){
	return this->_msg.c_str();
}