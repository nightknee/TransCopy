#include "copyworker.h"

CopyWorker::CopyWorker(const CopyHandler &copyHandler)
{
    this->copyHandler = copyHandler;
}

void CopyWorker::startCopy()
{
    this->copyHandler.copy();
}
