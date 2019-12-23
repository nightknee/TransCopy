#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>

#include "ui_mainwindow.h"
#include "CopyStatus.h"
#include "copyworker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    constexpr static int WINDOW_WEIGHT = 1600;
    constexpr static int WINDOW_HEIGHT = 1300;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void clickCopyButton();
    void sourceFilePathChanged();
    void destinationPathChanged();
    void handleBeforeStartCopy();
    void updateCopyProgress();
    void handleFinishedCopy();
    void getSourceFilePath();
    void getDestinationPath();

private:
    Ui::MainWindow *ui;

    void setLabels();
    void hideElementsBeforeRun();

    void initSingalsToSlots();
    void showLabelsAndProgressBar();

    void updateInformationAboutCopyProgress(copyStatusPtr status);

    void setValueToProgressBar(int value);

    void disableButtons();

    void enableButtons();

    void startCopy();
};

#endif // MAINWINDOW_H
