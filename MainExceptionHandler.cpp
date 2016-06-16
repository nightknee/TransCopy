#include "MainExceptionHandler.h"
#include "TransCopyConfiguration.h"


void MainExceptionHandler::handleException(BaseException* e){
	TransCopyConfiguration::getConfiguration().isDebug() ? std::cout<<e->getExceptionName()<<": " : std::cout<<"";
	std::cout<<e->getMessage()<<std::endl;
}
