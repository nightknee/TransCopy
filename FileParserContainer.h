#ifndef FileParserContainer_h
#define FileParserContainer_h

#include <map>
#include <string>
#include <memory>

#include "AbstractFileParse.h"
#include "PlsParser.h"
#include "Exceptions/BaseException.h"

typedef std::map<std::string,AbstractFileParse*> playlistMap;
class FileParserContainer {

 public:	
	FileParserContainer();	

    AbstractFileParse* findParser(std::string fileExtension);
	
	static FileParserContainer& getInstance();
	
	void insertParser(std::string playlistExtenstion,AbstractFileParse* newParser);

 private:
    playlistMap parsers;
};

#endif // PlaylistParserContainer_h
