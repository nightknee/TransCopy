#include "FileNotExistException.h" 

FileNotExistException::FileNotExistException(){}

FileNotExistException::FileNotExistException(std::string msg) : BaseException(msg){}