#ifndef MAINEXCEPTIONHANDLER_H
#define MAINEXCEPTIONHANDLER_H

#include <iostream>

#include "Exceptions/BaseException.h"

/**
 * @class MainExceptionHandler
 * @file MainExceptionHandler.h
 * @brief Format exception messages and display it in console mode
 */

class MainExceptionHandler {
public:
    MainExceptionHandler();
    /**
     * @brief Display messages from exceptions in TransCopy
     * @param e
     */
    static void handleException(const BaseException* e);
    /**
     * @brief Display messages from std::exception
     * @param e
     */
    static void handleException(const std::exception* e);
};

#endif // MAINEXCEPTIONHANDLER_H
