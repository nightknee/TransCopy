#ifndef DEFAULTOUTPUT_H
#define DEFAULTOUTPUT_H

#include <iostream>

#include "Output.h"
#include "CmdOptionsDescription.h"

class DefaultOutput : public Output {
public:
    virtual Output& operator<<(const std::string& str);
    void sendOutput(const std::string& str);
    
    virtual Output& operator<<(const CmdOptionsDescription& desc);
    void sendOutput(const CmdOptionsDescription& desc);
};

#endif /* DEFAULTOUTPUT_H */

