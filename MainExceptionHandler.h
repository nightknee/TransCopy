#ifndef MAINEXCEPTIONHANDLER_H
#define MAINEXCEPTIONHANDLER_H

#include <iostream>

#include "Exceptions/BaseException.h"

class MainExceptionHandler
{
public:
	MainExceptionHandler();
	static void handleException(BaseException* e);
	static bool showExceptionName();
};

#endif // MAINEXCEPTIONHANDLER_H
