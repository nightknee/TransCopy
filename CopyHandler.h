#ifndef COPYHANDLER_H
#define COPYHANDLER_H

#include <string>

#include "File.h"
#include "FileFactory.h"
#include "Directory.h"
#include "DirectoryFactory.h"
#include "AbstractFileParse.h"
#include "FileParserContainer.h"
#include "ParsedFiles.h"

class CopyHandler {
public:    
    CopyHandler(const std::string& filePath, const std::string& directoryPath);
    void copy();
    ~CopyHandler();
private:
    void copyParsedFiles(const ParsedFiles *files, const directoryPtr &destination);
    std::string filePath;
    std::string directoryPath;
};

#endif // COPYHANDLER_H
