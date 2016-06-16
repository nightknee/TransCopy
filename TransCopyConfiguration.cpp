#include "TransCopyConfiguration.h"
#include <iostream>


std::string TransCopyConfiguration::getPlaylistPath()
{
	return this->playlistPath;
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
	this->playlistPath = configuration->playlistPath;
	
	this->destinationPath = configuration->destinationPath;
	
	this->gui = configuration->gui;
}

bool TransCopyConfiguration::isDebug(){
	return this->debug;
}