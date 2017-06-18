#ifndef PARSEDFILES_H
#define PARSEDFILES_H

#include <boost/ptr_container/ptr_vector.hpp>

#include "File.h"

typedef boost::ptr_vector<File> ParsedFilesStorage;

class ParsedFiles{
public:
    void addFile(File *file);
    bool isEmpty() const;
    ParsedFilesStorage* getParsedFilesStorage() const;
    const uintmax_t& size() const;
private:
    void appendToFileSize(const File *file);
    uintmax_t allFileSize;
    ParsedFilesStorage files;    
};

#endif /* PARSEDFILES_H */

