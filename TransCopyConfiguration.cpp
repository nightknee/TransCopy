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
}

void TransCopyConfiguration::setConfiguration(Configuration *configuration){
	this->_fileToParsePath = configuration->fileToParsePath;
	
	this->_destinationPath = configuration->destinationPath;
	
	this->_gui = configuration->gui;
}

bool TransCopyConfiguration::isDebug(){
	return this->_debug;
}

void TransCopyConfiguration::pathValidResult(bool result){
	this->_pathIsValid;
}

void TransCopyConfiguration::fileValidResult(bool result){
	this->_fileIsValid;
}

bool TransCopyConfiguration::fileValidationResult(){
	return this->_fileIsValid;
}
	
bool TransCopyConfiguration::pathValidationResult(){
	return this->_pathIsValid;
}