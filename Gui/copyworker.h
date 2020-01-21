#ifndef COPYWORKER_H
#define COPYWORKER_H

#include <QObject>
//#include <thread>
#include <boost/thread.hpp>

#include "CopyHandler.h"

class CopyWorker : public QObject
{
    Q_OBJECT
public:
    CopyWorker(const std::string& filePath, const std::string& directoryPath);

public slots:
    void startCopy();

private:
    CopyHandler* copyHandler;
    void addCopyHandlerSlot();
    void addFinischCopyHandlerSlot();

    void handleAfetCopyFile(copyStatusPtr);
    void handleFinishCopy();

signals:
    void beforeCopy();
    void changeCopyStatus(copyStatusPtr);
    void finishedCopy();
};

#endif // COPYWORKER_H
