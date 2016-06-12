#include "PlaylistParserContainer.h"

void PlaylistParserContainer::ParserContainer(){

}

playlistMap::iterator PlaylistParserContainer::findParser(std::string playlistExtension){
	playlistMap::iterator findedParserIt = this->parsers.find(playlistExtension);
	
	return findedParserIt;	
}

