#include "ParsedFiles.h"

void ParsedFiles::addFile(const File *file) {
    this->files.push_back(file);
    
    this->appendToFileSize(file);
}

bool ParsedFiles::isEmpty() {
    return this->files.size() <= 0 ? true : false;
}

void ParsedFiles::appendToFileSize(const File *file) {
    this->allFileSize += file->size();
}

ParsedFilesStorage* ParsedFiles::getParsedFilesStorage() {
    return &(this->files);
}

uintmax_t ParsedFiles::size() {
    return this->allFileSize;
}