#include "TransCopyConfiguration.h"
#include <iostream>

using namespace std;



std::string TransCopyConfiguration::getPlaylistPath()
{
	return this->playlistPath;
}


std::string TransCopyConfiguration::getDestinationPath()
{
	return this->playlistPath;
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
	cout<<"Configuration make";
}

void TransCopyConfiguration::setConfiguration(Configuration *configuration){
	this->playlistPath = configuration->playlistPath;
	
	this->destinationPath = configuration->destinationPath;
	
	this->gui = configuration->gui;
}