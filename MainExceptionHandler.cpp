#include "MainExceptionHandler.h"

void MainExceptionHandler::handleException(BaseException* e){
	MainExceptionHandler::showExceptionName() ? std::cout<<e->getExceptionName()<<": " : std::cout<<"";
	std::cout<<e->getMessage()<<std::endl;
}

bool MainExceptionHandler::showExceptionName(){
	return true;
}