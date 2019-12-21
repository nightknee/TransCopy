#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setLabels();

    this->hideElementsBeforeRun();

    this->setFixedSize(MainWindow::WINDOW_WEIGHT,MainWindow::WINDOW_HEIGHT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabels()
{
    this->ui->sourceFileButton->setText(tr("Source file"));
    this->ui->destinationButton->setText(tr("Destination"));

    this->ui->allFilesLabel->setText(tr("All files:"));
    this->ui->allFilesValue->setText(0);

    this->ui->copiedFilesLabel->setText(tr("Copied files:"));
    this->ui->copiedFilesValue->setText(tr("0"));

    this->ui->copiedFilesSizeLabel->setText(tr("Copied files size:"));
    this->ui->copiedFilesSizeValue->setText(tr("0"));

    this->ui->failedCopiedFilesLabel->setText(tr("Failed copied files:"));
    this->ui->failedCopiedFilesValue->setText(tr("0"));

    this->ui->startCopyButton->setText(tr("Start copy"));

    this->ui->copyProgress->setValue(0);
}

void MainWindow::hideElementsBeforeRun()
{
    this->ui->allFilesLabel->hide();
    this->ui->allFilesValue->hide();

    this->ui->copiedFilesLabel->hide();
    this->ui->copiedFilesValue->hide();

    this->ui->copiedFilesSizeLabel->hide();
    this->ui->copiedFilesSizeValue->hide();

    this->ui->failedCopiedFilesLabel->hide();
    this->ui->failedCopiedFilesValue->hide();

    this->ui->copyProgress->hide();
}
