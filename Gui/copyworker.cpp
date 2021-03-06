#include "copyworker.h"


CopyWorker::CopyWorker(const std::string& filePath, const std::string& directoryPath)
{
    this->copyHandler = new CopyHandler(filePath, directoryPath);

    this->addBeforeStartCopySlot();
    this->addCopyHandlerSlot();
    this->addFinischCopyHandlerSlot();
}

CopyWorker::~CopyWorker()
{
    delete this->copyHandler;
}

void CopyWorker::startCopy()
{
    emit beforeRunCopyHandler();

    copyStatusPtr copyStats = this->copyHandler->getCopyStatus();

    boost::thread t(&CopyHandler::copy, this->copyHandler);

    t.detach();
}

void CopyWorker::addBeforeStartCopySlot()
{
    this->copyHandler->beforeStartCopy.connect(boost::bind(&CopyWorker::handleBeforeStartCopy, this, _1));
}

void CopyWorker::addCopyHandlerSlot()
{
    this->copyHandler->afterCopyFile.connect(boost::bind(&CopyWorker::handleAfetCopyFile, this, _1));
}

void CopyWorker::addFinischCopyHandlerSlot()
{
    this->copyHandler->finishedCopy.connect(boost::bind(&CopyWorker::handleFinishCopy, this));
}

void CopyWorker::handleBeforeStartCopy(copyStatusPtr copyStats)
{
    emit beforeCopy(copyStats);
}

void CopyWorker::handleAfetCopyFile(copyStatusPtr status)
{
    emit changeCopyStatus(status);
}

void CopyWorker::handleFinishCopy()
{
    emit finishedCopy();
}
