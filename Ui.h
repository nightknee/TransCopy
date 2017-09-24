#ifndef UI_H
#define UI_H

#include "TransCopy.h"

class TransCopy;

class Ui {
public:
    virtual int run(int argc, char** argv, const TransCopy &desc) = 0;
protected:
    virtual void setConfigurationFromCmd(int argc, char** argv, const CmdOptionsDescriptionPtr &desc) = 0;
};

#endif /* UI_H */

