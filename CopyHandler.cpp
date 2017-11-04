#include "CopyHandler.h"

CopyHandler::CopyHandler(const std::string& filePath, const std::string& directoryPath) {
    this->filePath = std::move(filePath);
    this->directoryPath = std::move(directoryPath);
}

CopyHandler::~CopyHandler() {
}

void CopyHandler::copy() {
    const filePtr fileToParse = FileFactory::create(this->filePath);
    const directoryPtr destination = DirectoryFactory::create(this->directoryPath);
    const AbstractFileParse *parser = FileParserContainer::getInstance().findParser(fileToParse->getExntenstion());

    const ParsedFiles* parsedFiles = parser->parse(fileToParse);

    if (!parsedFiles->isEmpty()) {
        this->copyParsedFiles(parsedFiles, destination);
    }
}

void CopyHandler::copyParsedFiles(const ParsedFiles *parsedFiles, const directoryPtr &destination) {
    ParsedFilesStorage* parsedFilesStor = parsedFiles->getParsedFilesStorage();
    
    this->copyStatus->setAllFilesSize(parsedFiles->size());
    this->copyStatus->setNumberOfAllFiles(parsedFilesStor->size());
    
    for (ParsedFilesStorage::iterator i = parsedFilesStor->begin(); i != parsedFilesStor->end(); ++i) {
        if (destination->copyFile(*i)) {
            this->copyStatus->increaseCopiedNumberFiles();
            this->copyStatus->addCopiedFileSize((*i)->size());
        }
    }
}

copyStatusPtr CopyHandler::getCopyStatus() {
    return this->copyStatus;
}
