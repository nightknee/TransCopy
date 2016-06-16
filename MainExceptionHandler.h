#ifndef MAINEXCEPTIONHANDLER_H
#define MAINEXCEPTIONHANDLER_H

#include <iostream>

#include "Exceptions/BaseException.h"

class MainExceptionHandler
{
public:
	MainExceptionHandler();
	static void handleException(BaseException* e);
};

#endif // MAINEXCEPTIONHANDLER_H
