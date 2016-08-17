#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <string>
/**
 * @class BaseException
 * @file BaseException.h
 * @brief  Base class for all exceptions throwing in TransCopy
 */
class BaseException : public std::exception{
public:
	/**
	 @brief Set BaseException::_msg
	 @param msg Messege throwing in exception
	 */
	BaseException(std::string msg);
	BaseException();
	/**
	 *  Return messege content
	 * @return Exception messege content seted in _msg
	 */
	virtual const char* what() const throw();
protected:
	/**
		@brief  Exception messeege
	 */
	std::string _msg;		
};

#endif // BASEEXCEPTION_H
