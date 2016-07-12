#include "TransCopyConfiguration.h"
#include <iostream>


std::string TransCopyConfiguration::getFileToParsePath()
{
	return this->fileToParsePath;
}


std::string TransCopyConfiguration::getDestinationPath()
{
	return this->destinationPath;
}


bool TransCopyConfiguration::withGui()
{
    return this->gui;
}


TransCopyConfiguration& TransCopyConfiguration::getConfiguration(){
	static TransCopyConfiguration instance;
	return instance;
}

TransCopyConfiguration::TransCopyConfiguration(){
	this->gui = false;
	this->debug = true;
}

void TransCopyConfiguration::setConfiguration(Configuration *configuration){
	this->fileToParsePath = configuration->fileToParsePath;
	
	this->destinationPath = configuration->destinationPath;
	
	this->gui = configuration->gui;
}

bool TransCopyConfiguration::isDebug(){
	return this->debug;
}

void TransCopyConfiguration::pathValidResult(bool result){
	this->pathIsValid;
}

void TransCopyConfiguration::fileValidResult(bool result){
	this->fileIsValid;
}