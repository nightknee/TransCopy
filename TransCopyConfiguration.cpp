#include "TransCopyConfiguration.h"
#include <iostream>

using namespace std;



std::string TransCopyConfiguration::getPlaylistPath()
{
}


std::string TransCopyConfiguration::getDestinationPath()

{
}


int TransCopyConfiguration::withGui()
{
    return 0;
}


TransCopyConfiguration& TransCopyConfiguration::getConfiguration(){
	static TransCopyConfiguration instance;
	return instance;
}

TransCopyConfiguration::TransCopyConfiguration(){
	cout<<"Configuration make";
}