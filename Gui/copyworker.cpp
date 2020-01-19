#include "copyworker.h"


CopyWorker::CopyWorker(const std::string& filePath, const std::string& directoryPath)
{
    this->copyHandler = new CopyHandler(filePath, directoryPath);

    this->addCopyHandlerSlot();
    this->addFinischCopyHandlerSlot();
}

void CopyWorker::startCopy()
{
    copyStatusPtr copyStats = this->copyHandler->getCopyStatus();

    emit beforeCopy();

    boost::thread t(&CopyHandler::copy, this->copyHandler);

    t.detach();
}

void CopyWorker::addCopyHandlerSlot()
{
    this->copyHandler->afterCopyFile.connect(boost::bind(&CopyWorker::handleAfetCopyFile, this, _1));
}

void CopyWorker::addFinischCopyHandlerSlot()
{
//    this->copyHandler->finishedCopy.connect(boost::bind(&CopyWorker::handleFinishCopy, this, _1));
}

void CopyWorker::handleAfetCopyFile(copyStatusPtr &status)
{
    emit changeCopyStatus(status);
}

void CopyWorker::handleFinishCopy()
{
    emit finishedCopy();
}
