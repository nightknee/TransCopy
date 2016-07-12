#include "PlaylistParserContainer.h"
#include "Exceptions/NotFoundParserException.h"

#include <iostream>

PlaylistParserContainer::PlaylistParserContainer(){
	this->insertParser(".mp3",new PlsParser);
}

AbstractFileParse* PlaylistParserContainer::findParser(std::string playlistExtension){
	playlistMap::iterator It = this->parsers.find(playlistExtension);

	if(It == this->parsers.end()){
		throw new NotFoundParserException();		
	}
	
	AbstractFileParse *parser = It->second;
	return parser;
}

void PlaylistParserContainer::insertParser(std::string playlistExtenstion,AbstractFileParse* newParser){
	this->parsers.insert(std::pair<std::string,AbstractFileParse*>(playlistExtenstion,newParser));
}

PlaylistParserContainer& PlaylistParserContainer::getInstance(){
	static PlaylistParserContainer instance;
	return instance;
}