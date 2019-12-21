#include "qtgui.h"

QtGui::QtGui()
{

}

int QtGui::run(int argc, char **argv, cmdOptionsDescriptionPtr &desc)
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}

void QtGui::setConfigurationFromCmd(int argc, char **argv)
{

}
