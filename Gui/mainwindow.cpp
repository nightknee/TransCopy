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

}

void MainWindow::showLabelsAndProgressBar()
{

}

void MainWindow::updateInformationAboutCopyProgress(copyStatusPtr status)
{

}

void MainWindow::setValueToProgressBar(int value)
{

}

QString MainWindow::getSourceFilePath()
{
    return QFileDialog::getOpenFileName(
                this,
                tr("Open file"),
                "",
                tr("Playlist files (*.pls)")
           );
}

QString MainWindow::getDestinationPath()
{
    QString destinationPath;

    QFileDialog destinationDialog(this);

    destinationDialog.setFileMode(QFileDialog::Directory);

    if (destinationDialog.exec()) {
        destinationPath = destinationDialog.getOpenFileName();
    }

    return destinationPath;
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

}
