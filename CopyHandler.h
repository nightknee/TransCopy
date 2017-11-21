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
#include "CopyStatus.h"

class CopyHandler {
public:    
    CopyHandler(const std::string& filePath, const std::string& directoryPath);
    void copy();
    copyStatusPtr getCopyStatus();
    ~CopyHandler();
private:
    void copyParsedFiles(const ParsedFiles *files, const directoryPtr &destination);
    std::string filePath;
    std::string directoryPath;
    copyStatusPtr copyStatus;
};

#endif // COPYHANDLER_H
