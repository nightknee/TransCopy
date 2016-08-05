#include "FileParserContainer.h"
#include "Exceptions/NotFoundParserException.h"

#include <iostream>

FileParserContainer::FileParserContainer(){
	this->insertParser(".pls",new PlsParser);
}

AbstractFileParse* FileParserContainer::findParser(std::string playlistExtension){
	playlistMap::iterator It = this->parsers.find(playlistExtension);
	if(It == this->parsers.end()){
		throw new NotFoundParserException("Not found parser for: "+playlistExtension+" file");		
	}
	AbstractFileParse *parser = It->second;
	return parser;
}

void FileParserContainer::insertParser(std::string playlistExtenstion,AbstractFileParse* newParser){
	this->parsers.insert(std::pair<std::string,AbstractFileParse*>(playlistExtenstion,newParser));
}

FileParserContainer& FileParserContainer::getInstance(){
	static FileParserContainer instance;
	return instance;
}