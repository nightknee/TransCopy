#ifndef TransCopyConfiguration_h
#define TransCopyConfiguration_h

#include "TransCopyConfiguration.h"

#include "Configuration.h"


class TransCopyConfiguration {

public:
 
	TransCopyConfiguration();

	std::string getPlaylistPath();

	std::string getDestinationPath();

    bool withGui();	
	
	bool isDebug();
	
	void setConfiguration(Configuration* configuration);

	static TransCopyConfiguration&  getConfiguration();

private:
	std::string playlistPath;
	std::string destinationPath;
	bool gui;
	bool debug;
};

#endif // TransCopyConfiguration_h
