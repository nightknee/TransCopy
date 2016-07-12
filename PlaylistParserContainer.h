#ifndef PlaylistParserContainer_h
#define PlaylistParserContainer_h

#include <map>
#include <string>
#include <memory>

#include "AbstractFileParse.h"
#include "PlsParser.h"
#include "Exceptions/BaseException.h"

typedef std::map<std::string,AbstractFileParse*> playlistMap;
class PlaylistParserContainer {

 public:	
	PlaylistParserContainer();	

    AbstractFileParse* findParser(std::string playlistExtension);
	
	static PlaylistParserContainer& getInstance();
	
	void insertParser(std::string playlistExtenstion,AbstractFileParse* newParser);

 private:
    playlistMap parsers;
};

#endif // PlaylistParserContainer_h
