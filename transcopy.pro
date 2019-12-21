QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lboost_program_options -lboost_system -lboost_filesystem -lboost_regex -pthread

INCLUDEPATH += include\

SOURCES += \
    Cmd.cpp \
    CmdOptionsDescription.cpp \
    CmdOptionsParsed.cpp \
    CmdOptionsParser.cpp \
    CmdOutput.cpp \
    CopyHandler.cpp \
    CopyStatus.cpp \
    Directory.cpp \
    DirectoryFactory.cpp \
    DiskObject.cpp \
    Exceptions/BaseException.cpp \
    Exceptions/CmdOptionsParserException.cpp \
    Exceptions/FileException.cpp \
    Exceptions/NotFoundParserException.cpp \
    Exceptions/PathException.cpp \
    File.cpp \
    FileFactory.cpp \
    FileParserContainer.cpp \
    Gui/mainwindow.cpp \
    Gui/qtgui.cpp \
    MainExceptionHandler.cpp \
    ParsedFiles.cpp \
    PlsParser.cpp \
    SizeFormatter.cpp \
    TransCopy.cpp \
    TransCopyConfiguration.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    AbstractFileParse.h \
    Cmd.h \
    CmdOptionsDescription.h \
    CmdOptionsParsed.h \
    CmdOptionsParser.h \
    CmdOutput.h \
    CopyHandler.h \
    CopyStatus.h \
    Directory.h \
    DirectoryFactory.h \
    DiskObject.h \
    Exceptions/BaseException.h \
    Exceptions/CmdOptionsParserException.h \
    Exceptions/FileException.h \
    Exceptions/NotFoundParserException.h \
    Exceptions/PathException.h \
    File.h \
    FileFactory.h \
    FileParserContainer.h \
    Gui/mainwindow.h \
    Gui/qtgui.h \
    Logger.h \
    MainExceptionHandler.h \
    Output.h \
    ParsedFiles.h \
    PlsParser.h \
    SizeFormatter.h \
    TransCopy.h \
    TransCopyConfiguration.h \
    Ui.h \
    mainwindow.h

FORMS += \
    Gui/mainwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    bitbucket-pipelines.yml \
