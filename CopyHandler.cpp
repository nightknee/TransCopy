#include "CopyHandler.h"

CopyHandler::CopyHandler(const std::string& filePath, const std::string& directoryPath) {
    this->fileToParse = FileFactory::create(filePath);
    this->destination = DirectoryFactory::create(directoryPath);   
    
    SizeFormatter formatter;
    
    this->copyStatus = copyStatusPtr{new CopyStatus{formatter}};
}

CopyHandler::~CopyHandler() {}

void CopyHandler::copy() {
    const AbstractFileParse *parser = FileParserContainer::getInstance().findParser(this->fileToParse->getExntenstion());

    const ParsedFiles* parsedFiles = parser->parse(this->fileToParse);

    if (!parsedFiles->isEmpty()) {
        this->copyParsedFiles(parsedFiles);
    }
}

void CopyHandler::copyParsedFiles(const ParsedFiles *parsedFiles) {
    ParsedFilesStorage* parsedFilesStor = parsedFiles->getParsedFilesStorage();
    
    this->copyStatus->setAllFilesSize(parsedFiles->size());
    this->copyStatus->setNumberOfAllFiles(parsedFilesStor->size());
    
    this->beforeStartCopy(this->copyStatus);

    for (ParsedFilesStorage::iterator i = parsedFilesStor->begin(); i != parsedFilesStor->end(); ++i) {
        if (!this->destination->copyFile(*i)) {
            this->copyStatus->increaseFailedCopiedNumberFiles();
            continue;
        }
        
        this->copyStatus->increaseCopiedNumberFiles();
        this->copyStatus->addCopiedFileSize((*i)->size());

        this->afterCopyFile(this->copyStatus);
    }
    
    this->copyStatus->setFinishStatus(true);
    this->finishedCopy();
}

copyStatusPtr CopyHandler::getCopyStatus() {
    return this->copyStatus;
}
