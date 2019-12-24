#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->status = nullptr;

    ui->setupUi(this);

    this->setLabels();

    this->hideElementsBeforeRun();

    this->initSingalsToSlots();

//    this->setFixedSize(MainWindow::WINDOW_WEIGHT,MainWindow::WINDOW_HEIGHT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickCopyButton()
{

}

void MainWindow::sourceFilePathChanged()
{

}

void MainWindow::destinationPathChanged()
{

}

void MainWindow::handleBeforeStartCopy()
{

}

void MainWindow::updateCopyProgress()
{

}

void MainWindow::handleFinishedCopy()
{

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

void MainWindow::initSingalsToSlots()
{
    QObject::connect(this->ui->startCopyButton, SIGNAL(clicked()), this, SLOT(clickCopyButton()));
    QObject::connect(this->ui->sourceFileButton, SIGNAL(clicked()), this, SLOT(getSourceFilePath()));
    QObject::connect(this->ui->destinationButton, SIGNAL(clicked()), this, SLOT(getDestinationPath()));

    QObject::connect(this->ui->sourceFilePath, SIGNAL(textChanged()), this, SLOT(sourceFilePathChanged()));
    QObject::connect(this->ui->destinationPath, SIGNAL(textChanged()), this, SLOT(destinationPathChanged()));
}

void MainWindow::showLabelsAndProgressBar()
{

}

void MainWindow::updateInformationAboutCopyProgress()
{
    if (!this->status) {
        return;
    }
}

void MainWindow::setValueToProgressBar(int value)
{

}

void MainWindow::getSourceFilePath()
{
    QString path =  QFileDialog::getOpenFileName(
                this,
                tr("Open file"),
                "",
                tr("Playlist files (*.pls)")
           );

    this->ui->sourceFilePath->setText(path);
}

void MainWindow::getDestinationPath()
{
    QString destinationPathStr;

    QFileDialog destinationDialog(this);

    destinationDialog.setFileMode(QFileDialog::Directory);

    if (destinationDialog.exec()) {
        destinationPathStr = destinationDialog.getOpenFileName();
    }

    this->ui->destinationPath->setText(destinationPathStr);
}

void MainWindow::disableButtons()
{
    this->ui->sourceFileButton->setDisabled(true);
    this->ui->destinationButton->setDisabled(true);
    this->ui->startCopyButton->setDisabled(true);
}

void MainWindow::enableButtons()
{
    this->ui->sourceFileButton->setEnabled(true);
    this->ui->destinationButton->setEnabled(true);
    this->ui->startCopyButton->setEnabled(true);
}

void MainWindow::startCopy()
{
    CopyHandler copyHandler(
                    this->sourcePath().toStdString(),
                    this->destinationPath().toStdString()
                );

    this->status = copyHandler.getCopyStatus();

    QThread copyThread;
    CopyWorker *worker = new CopyWorker(copyHandler);
    worker->moveToThread(&copyThread);

    QObject::connect(worker, SIGNAL(CopyWorker::changeCopyStatus), this, SLOT(updateInformationAboutCopyProgress));
    QObject::connect(worker, SIGNAL(CopyWorker::finishedCopy), this, SLOT(handleFinishedCopy));

    QObject::connect(&copyThread, SIGNAL(QThread::start), worker, SLOT(CopyWorker::startCopy));

    copyThread.start();
}

QString MainWindow::sourcePath()
{
    return this->ui->sourceFilePath->text();
}

QString MainWindow::destinationPath()
{
    return this->ui->destinationPath->text();
}
