#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"

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

private:
    Ui::MainWindow *ui;

    void setLabels();
    void hideElementsBeforeRun();
};

#endif // MAINWINDOW_H
