#include "MainExceptionHandler.h"

void MainExceptionHandler::handleException(const BaseException& e) {
    std::cout << e.what() << std::endl;
}

void MainExceptionHandler::handleException(const std::exception& e) {
    std::cout << e.what() << std::endl;
}
