#ifndef TransCopyConfiguration_h
#define TransCopyConfiguration_h

#include "TransCopyConfiguration.h"

#include "Configuration.h"


class TransCopyConfiguration {

public:
 
	TransCopyConfiguration();

	std::string getFileToParsePath();

	std::string getDestinationPath();

    bool withGui();	
	
	bool isDebug();
	
	void setConfiguration(Configuration* configuration);
	
	void pathValidResult(bool result);
	
	void fileValidResult(bool result);

	static TransCopyConfiguration&  getConfiguration();

private:
	std::string fileToParsePath;
	std::string destinationPath;
	bool gui;
	bool debug;
	bool pathIsValid;
	bool fileIsValid;
};

#endif // TransCopyConfiguration_h
