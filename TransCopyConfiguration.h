#ifndef TransCopyConfiguration_h
#define TransCopyConfiguration_h

#include "TransCopyConfiguration.h"

#include "Configuration.h"


class TransCopyConfiguration {

 public:

	std::string getPlaylistPath();

	std::string getDestinationPath();

    bool withGui();	
	
	void setConfiguration(Configuration* configuration);

	static TransCopyConfiguration&  getConfiguration();
	

public:
	
	
	TransCopyConfiguration();

 private:
	std::string playlistPath;
	std::string destinationPath;
	bool gui;
};

#endif // TransCopyConfiguration_h
