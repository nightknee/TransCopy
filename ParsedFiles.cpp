#include "ParsedFiles.h"

void ParsedFiles::addFile(filePtr& file) {    
    this->appendToFileSize(file);
    this->files.push_back(std::move(file));       
}

bool ParsedFiles::isEmpty() const{
    return this->files.size() <= 0 ? true : false;
}

void ParsedFiles::appendToFileSize(filePtr& file) {
    this->allFileSize += file->size();
}

ParsedFilesStorage* ParsedFiles::getParsedFilesStorage() const{
    return const_cast<ParsedFilesStorage*>(&(this->files));
}

const uintmax_t& ParsedFiles::size() const{
    return this->allFileSize;
}