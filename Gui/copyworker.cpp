#include "copyworker.h"

CopyWorker::CopyWorker(const CopyHandler &copyHandler): copyHandler(copyHandler)
{

}

void CopyWorker::startCopy()
{
    copyStatusPtr copyStats = this->copyHandler.getCopyStatus();

    emit beforeCopy();

    std::thread t(&CopyHandler::copy, this->copyHandler);

    t.detach();

    while (!copyStats->isFinished()) {
        emit changeCopyStatus();
    }

    emit finishedCopy();
}
