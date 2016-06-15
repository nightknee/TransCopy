#ifndef PlaylistParserContainer_h
#define PlaylistParserContainer_h

#include <map>
#include <string>
#include <memory>

#include "AbstractPlaylistParse.h"
#include "PlsParser.h"

typedef std::map<std::string,AbstractPlaylistParse*> playlistMap;
class PlaylistParserContainer {

 public:	
	PlaylistParserContainer();	

    AbstractPlaylistParse* findParser(std::string playlistExtension);
	
	static PlaylistParserContainer& getInstance();
	
	void insertParser(std::string playlistExtenstion,AbstractPlaylistParse* newParser);

 private:
    playlistMap parsers;
};

#endif // PlaylistParserContainer_h
