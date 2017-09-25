#ifndef DEFAULTOUTPUT_H
#define DEFAULTOUTPUT_H

#include <iostream>

#include "Output.h"
#include "CmdOptionsDescription.h"
#include "Exceptions/BaseException.h"

class CmdOutput : public Output {
public:
    virtual Output& operator<<(const std::string& str);
    void sendOutput(const std::string& str);
    
    virtual CmdOutput& operator<<(const CmdOptionsDescription& desc);
    void sendOutput(const CmdOptionsDescription& desc);
    
    virtual CmdOutput& operator<<(const BaseException* e);
    void sendOutput(const BaseException* e);
    
    virtual CmdOutput& operator<<(std::exception* e);
    void sendOutput(std::exception* e);    
};

#endif /* DEFAULTOUTPUT_H */

