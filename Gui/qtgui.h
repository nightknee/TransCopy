#ifndef QTGUI_H
#define QTGUI_H

#include <QApplication>

#include "mainwindow.h"
#include "Ui.h"

class QtGui : public TransCopySpace::Ui
{

public:
    QtGui();

    virtual int run(int argc, char** argv, cmdOptionsDescriptionPtr &desc) ;

private:
    virtual void setConfigurationFromCmd(int argc, char** argv);
};

#endif // QTGUI_H
