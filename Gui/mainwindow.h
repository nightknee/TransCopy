#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QThread>

#include "ui_mainwindow.h"
#include "CopyStatus.h"
#include "copyworker.h"
#include "../Exceptions/NotFoundParserException.h"
#include "FileParserContainer.h"
#include "File.h"
#include "Directory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    constexpr static int WINDOW_WEIGHT = 820;
    constexpr static int WINDOW_HEIGHT = 520;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void clickCopyButton();
    void sourceFilePathChanged(const QString &text);
    void destinationPathChanged(const QString &text);
    void handleBeforeStartCopy();
    void updateCopyProgress();
    void handleFinishedCopy();
    void getSourceFilePath();
    void getDestinationPath();
    void checkValidPath(const QString &text);
    void updateInformationAboutCopyProgress(copyStatusPtr);

private:
    Ui::MainWindow *ui;

    QString sourceFilePathStr;
    bool sourceFilePathIsValid = false;
    void setSourcePathAsValid();
    void setSourcePathInvalid();
    bool sourcePathIsValid();

    QString* destinationPathStr;
    bool destinationPathIsValid = false;
    void setDestinationPathAsValid();
    void setDestinationPathInvalid();
    bool destinationIsValid();
    QString* validDestinationToCopy(const QString& destination);

    void setLabels();
    void hideElementsBeforeRun();

    void initSingalsToSlots();
    void showLabelsAndProgressBar();   

    void setValueToProgressBar(int value);

    void disableButtons();

    void enableButtons();

    void startCopy();

    void enableCopyButton();
    void disableCopyButton();

    bool pathsAreValid();

    QString sourcePath();
    const QString destinationPath();

    void errorPathLabelText(const QString &text);
    void errorDestinationLabelText(const QString &text);
    void clearErrorSourcePathLabel();
    void clearErrorDestinationPathLabel();

    QString allFilesValue;
    QString copiedFilesValue;
    QString copiedFilesSizeValue;
    QString failedCopiedFilesValue;
    int copyProgress;

    QThread *copyThread = nullptr;

};

#endif // MAINWINDOW_H
