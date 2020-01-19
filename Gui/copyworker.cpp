#include "copyworker.h"


CopyWorker::CopyWorker(const std::string& filePath, const std::string& directoryPath)
{
    this->copyHandler = new CopyHandler(filePath, directoryPath);
}

void CopyWorker::startCopy()
{
    copyStatusPtr copyStats = this->copyHandler->getCopyStatus();

    emit beforeCopy();

    std::thread t(&CopyHandler::copy, this->copyHandler);

    t.detach();

    QString formatedToCopy;

    while (!copyStats->isFinished()) {
        emit changeCopyStatus(copyStats);
    }

    emit finishedCopy();
}
