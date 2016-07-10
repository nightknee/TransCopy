#include "MainExceptionHandler.h"


void MainExceptionHandler::handleException(BaseException& e){
	std::cout<<e.what()<<std::endl;
}

void MainExceptionHandler::handleException(std::exception& e){
	std::cout<<e.what()<<std::endl;
}
