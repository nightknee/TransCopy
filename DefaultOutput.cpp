#include "DefaultOutput.h"

Output& DefaultOutput::operator <<(const std::string& str) {
    this->sendOutput(str);
    
    return *this;
}

void DefaultOutput::sendOutput(const std::string& str) {
    std::cout<<str<<std::endl;;
}

Output& DefaultOutput::operator <<(const CmdOptionsDescription& desc) {
    this->sendOutput(desc);
    
    return *this;
}

void DefaultOutput::sendOutput(const CmdOptionsDescription& desc) {
    std::cout<<desc<<std::endl;
}