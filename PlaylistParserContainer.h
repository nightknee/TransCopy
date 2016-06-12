#ifndef PlaylistParserContainer_h
#define PlaylistParserContainer_h

#include <map>
#include <string>

#include "AbstractPlaylistParse.h"
#include "PlsParser.h"

typedef std::map<std::string,AbstractPlaylistParse&> playlistMap;
class PlaylistParserContainer {

 public:	
    void ParserContainer();

    playlistMap::iterator findParser(std::string playlistExtension);

 private:
    playlistMap parsers;
};

#endif // PlaylistParserContainer_h
