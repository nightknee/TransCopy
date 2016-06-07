#ifndef TransCopyConfiguration_h
#define TransCopyConfiguration_h

#include "TransCopyConfiguration.h"
#include <string>


class TransCopyConfiguration {

 public:

	std::string getPlaylistPath();

	std::string getDestinationPath();

    int withGui();

	static TransCopyConfiguration&  getConfiguration();
	

public:
	
	
	TransCopyConfiguration();

 private:
	std::string playlistPath;
	std::string destinationPath;
	int gui;
};

#endif // TransCopyConfiguration_h
