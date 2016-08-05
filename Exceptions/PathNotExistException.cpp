#include "PathNotExistException.h" 

PathNotExistException::PathNotExistException(){}

PathNotExistException::PathNotExistException(std::string msg) : BaseException(msg){}