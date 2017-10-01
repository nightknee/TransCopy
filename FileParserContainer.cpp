#include "FileParserContainer.h"
#include "Exceptions/NotFoundParserException.h"

#include <iostream>

FileParserContainer::FileParserContainer() {
    this->insertParser(".pls", new PlsParser);
}

AbstractFileParse* FileParserContainer::findParser(const std::string &fileExtension) {
    filesMap::iterator It = this->parsers.find(fileExtension);
    if (It == this->parsers.end()) {
        throw NotFoundParserException("Not found parser for " + fileExtension + " extension");
    }
    AbstractFileParse *parser = It->second;
    
    return parser;
}

void FileParserContainer::insertParser(const std::string &playlistExtenstion, AbstractFileParse* newParser) {
    this->parsers.insert(insertedType(playlistExtenstion, newParser));
}

FileParserContainer& FileParserContainer::getInstance() {
    static FileParserContainer instance;
    
    return instance;
}
