#include "copyworker.h"


CopyWorker::CopyWorker(const std::string& filePath, const std::string& directoryPath)
{
    this->copyHandler = new CopyHandler(filePath, directoryPath);

    this->addCopyHandlerSlot();
}

void CopyWorker::startCopy()
{
    copyStatusPtr copyStats = this->copyHandler->getCopyStatus();

    emit beforeCopy();

    boost::thread t(&CopyHandler::copy, this->copyHandler);

    t.detach();

//    while (!copyStats->isFinished()) {
//        emit changeCopyStatus(copyStats);
//    }

//    emit finishedCopy();
}

void CopyWorker::addCopyHandlerSlot()
{

}

void CopyWorker::handleAfetCopyFile(copyStatusPtr &status)
{
    emit changeCopyStatus(status);
}
