#ifndef COPYWORKER_H
#define COPYWORKER_H

#include <QObject>
#include <thread>

#include "CopyHandler.h"

class CopyWorker : public QObject
{
    Q_OBJECT
public:
    CopyWorker(const CopyHandler &copyHandler);

public slots:
    void startCopy();

private:
    CopyHandler copyHandler;

signals:
    void changeCopyStatus();
    void finishedCopy();
};

#endif // COPYWORKER_H
