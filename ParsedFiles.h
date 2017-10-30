#ifndef PARSEDFILES_H
#define PARSEDFILES_H

#include "File.h"
#include "FileFactory.h"

typedef std::vector<filePtr> ParsedFilesStorage;

class ParsedFiles {
public:
    void addFile(filePtr& file);
    bool isEmpty() const;
    ParsedFilesStorage* getParsedFilesStorage() const;
    const uintmax_t& size() const;
private:
    void appendToFileSize(filePtr& file);
    uintmax_t allFileSize;
    ParsedFilesStorage files;
};

#endif /* PARSEDFILES_H */

