#include "PlaylistParserContainer.h"
#include <iostream>

PlaylistParserContainer::PlaylistParserContainer(){
	this->insertParser(".mp3",new PlsParser);
}

AbstractPlaylistParse* PlaylistParserContainer::findParser(std::string playlistExtension){
	playlistMap::iterator It = this->parsers.find(playlistExtension);
	/**
	 * @todo Not found parser exception 
	 */ 
	if(It == this->parsers.end()){
		std::cout<<"Blad"<<std::endl;
	}
	AbstractPlaylistParse *parser = It->second;
	return parser;
}

void PlaylistParserContainer::insertParser(std::string playlistExtenstion,AbstractPlaylistParse* newParser){
	this->parsers.insert(std::pair<std::string,AbstractPlaylistParse*>(playlistExtenstion,newParser));
}

PlaylistParserContainer& PlaylistParserContainer::getInstance(){
	static PlaylistParserContainer instance;
	return instance;
}