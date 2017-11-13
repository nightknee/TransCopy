#include "CmdOutput.h"

Output& CmdOutput::operator<<(const std::string& str) {
    this->sendOutput(str);

    return *this;
}

void CmdOutput::sendOutput(const std::string& str) {
    std::cout << str;
}

CmdOutput& CmdOutput::operator<<(const CmdOptionsDescription& desc) {
    this->sendOutput(desc);

    return *this;
}

void CmdOutput::sendOutput(const CmdOptionsDescription& desc) {
    std::cout << desc;
}

CmdOutput& CmdOutput::operator<<(const BaseException &e) {
    this->sendOutput(e);

    return *this;
}

void CmdOutput::sendOutput(const BaseException &e) {
    std::cout << e.what();
}

CmdOutput& CmdOutput::operator<<(std::exception &e) {
    this->sendOutput(e);

    return *this;
}

void CmdOutput::sendOutput(std::exception &e) {
    std::cout << e.what();
}

CmdOutput& CmdOutput::operator<<(const copyStatusPtr &status) {
    this->sendOutput(status);
    
    return *this;
}
void CmdOutput::sendOutput(const copyStatusPtr &status) {
    std::cout << "\r";
    std::cout << "Copied: " << status->getCopiedNumberFiles() << " of  " << status->getNumberOfAllFiles() << " files " << "and " << status->getFailedCopiedFilesSize() << " failed coping files";
    std::cout << " Copied: " << status->getCopiedFilesSize() << " of  " << status->getAllFilesSize() << " bytes ";
    std::cout << "\r";
}  

const std::string CmdOutput::NEW_LINE = "\n";
const std::string CmdOutput::TAB = "\t";