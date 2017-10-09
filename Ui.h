#ifndef UI_H
#define UI_H

#include "TransCopy.h"

class Ui {
public:
    virtual int run(int argc, char** argv, cmdOptionsDescriptionPtr &desc) = 0;
protected:
    virtual void setConfigurationFromCmd(int argc, char** argv) = 0;
};

#endif /* UI_H */

