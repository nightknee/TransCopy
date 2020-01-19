#ifndef COPYHANDLER_H
#define COPYHANDLER_H

#include <string>
#include <boost/signals2.hpp>

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

//    boost::signals2::signal <void(copyStatusPtr)> afterCopyStatus;
private:
    void copyParsedFiles(const ParsedFiles *files);
    copyStatusPtr copyStatus;
    filePtr fileToParse;
    directoryPtr destination;    
};

#endif // COPYHANDLER_H
