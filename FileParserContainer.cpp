#include "FileParserContainer.h"
#include "Exceptions/NotFoundParserException.h"

#include <iostream>

FileParserContainer::FileParserContainer(){
	this->insertParser(".pls",new PlsParser);
}

AbstractFileParse* FileParserContainer::findParser(std::string fileExtension){
	playlistMap::iterator It = this->_parsers.find(fileExtension);
	if(It == this->_parsers.end()){
		throw new NotFoundParserException("Not found parser for "+fileExtension+" extension");		
	}
	AbstractFileParse *parser = It->second;
	return parser;
}

void FileParserContainer::insertParser(std::string playlistExtenstion,AbstractFileParse* newParser){
	this->_parsers.insert(std::pair<std::string,AbstractFileParse*>(playlistExtenstion,newParser));
}

FileParserContainer& FileParserContainer::getInstance(){
	static FileParserContainer instance;
	return instance;
}