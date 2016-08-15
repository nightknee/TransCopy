#include "TransCopyConfiguration.h"

std::string TransCopyConfiguration::getFileToParsePath()
{
	return this->_fileToParsePath;
}


std::string TransCopyConfiguration::getDestinationPath()
{
	return this->_destinationPath;
}


bool TransCopyConfiguration::withGui()
{
    return this->_gui;
}


TransCopyConfiguration& TransCopyConfiguration::getConfiguration(){
	static TransCopyConfiguration instance;
	return instance;
}

TransCopyConfiguration::TransCopyConfiguration(){
	this->_gui = false;
	this->_debug = true;
	this->_notyficate = false;
}

void TransCopyConfiguration::setConfiguration(Configuration *configuration){
	this->_fileToParsePath = configuration->fileToParsePath;
	
	this->_destinationPath = configuration->destinationPath;
	
	this->_gui = configuration->gui;
	
	this->_notyficate = configuration->notyficate;
}

bool TransCopyConfiguration::isDebug(){
	return this->_debug;
}

void TransCopyConfiguration::pathValidResult(bool result){
	this->_pathIsValid = result;
}

void TransCopyConfiguration::fileValidResult(bool result){
	this->_fileIsValid= result;
}

bool TransCopyConfiguration::fileValidationResult(){
	return this->_fileIsValid;
}
	
bool TransCopyConfiguration::pathValidationResult(){
	return this->_pathIsValid;
}

bool TransCopyConfiguration::notyficate(){
	return this->_notyficate;
}

void TransCopyConfiguration::setNotyficate(bool result){
	this->_notyficate = result;
}