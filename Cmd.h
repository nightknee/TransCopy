#ifndef CMD_H
#define CMD_H

#include "Ui.h"
#include "CmdOptionsDescription.h"
#include "CmdOptionsParser.h"

class Cmd : public Ui{
public:
    virtual int run(int argc, char** argv, TransCopy *tr);
private:
    virtual void setConfigurationFromCmd(int argc, char** argv, TransCopy *tr);
    std::shared_ptr<CmdOptionsDescription> getOptionsDescription(std::shared_ptr<CmdOptionsDescription>  desc);
};

#endif /* CMD_H */

