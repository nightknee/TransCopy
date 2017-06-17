#ifndef PARSEDFILES_H
#define PARSEDFILES_H

#include <boost/ptr_container/ptr_vector.hpp>

#include "File.h"

typedef boost::ptr_vector<File> ParsedFilesStorage;

class ParsedFiles{
public:
    void addFile(const File *file);
    bool isEmpty();
    ParsedFilesStorage* getParsedFilesStorage();
    uintmax_t size();
private:
    void appendToFileSize(const File *file);
    uintmax_t allFileSize;
    ParsedFilesStorage files;    
};

#endif /* PARSEDFILES_H */

