#ifndef COPYWORKER_H
#define COPYWORKER_H

#include <QObject>

#include "CopyHandler.h"

class CopyWorker : public QObject
{
public:
    CopyWorker(const CopyHandler &copyHandler);

public slots:
    void startCopy();

private:
    CopyHandler copyHandler;

signals:
    void changeCopyStatus(copyStatusPtr copyStatus);
    void finishedCopy();
};

#endif // COPYWORKER_H
