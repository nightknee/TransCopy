#include "copyworker.h"

CopyWorker::CopyWorker(const CopyHandler &copyHandler): copyHandler(copyHandler)
{

}

void CopyWorker::startCopy()
{
    this->copyHandler.copy();
}
