#include "CmdOutput.h"

Output& CmdOutput::operator<<(const std::string& str) {
    this->sendOutput(str);

    return *this;
}

void CmdOutput::sendOutput(const std::string& str) {
    std::cout << str << std::endl;
}

CmdOutput& CmdOutput::operator<<(const CmdOptionsDescription& desc) {
    this->sendOutput(desc);

    return *this;
}

void CmdOutput::sendOutput(const CmdOptionsDescription& desc) {
    std::cout << desc << std::endl;
}

CmdOutput& CmdOutput::operator<<(const BaseException* e) {
    this->sendOutput(e);

    return *this;
}

void CmdOutput::sendOutput(const BaseException* e) {
    std::cout << e->what() << std::endl;
}

CmdOutput& CmdOutput::operator<<(std::exception* e) {
    this->sendOutput(e);

    return *this;
}

void CmdOutput::sendOutput(std::exception* e) {
    std::cout << e->what() << std::endl;
}