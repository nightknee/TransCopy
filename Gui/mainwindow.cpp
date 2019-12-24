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

    this->disableCopyButton();

//    this->setFixedSize(MainWindow::WINDOW_WEIGHT,MainWindow::WINDOW_HEIGHT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickCopyButton()
{
    this->startCopy();
}

void MainWindow::sourceFilePathChanged(const QString &text)
{
    this->sourceFilePathStr = text;

    if (!File::isExist(this->sourceFilePathStr.toStdString())) {
        this->errorPathLabelText("File doesn't exist");
        this->setSourcePathInvalid();
        return;
    }

    this->setSourcePathAsValid();
}

void MainWindow::destinationPathChanged(const QString &text)
{
    this->destinationPathStr = text;

    if (!Directory::isExist(this->destinationPathStr.toStdString())) {
        this->errorDestinationLabelText("Directory doesn't exist");
        this->setDestinationPathInvalid();
        return;
    }

    this->setDestinationPathAsValid();
}

void MainWindow::handleBeforeStartCopy()
{
    this->showLabelsAndProgressBar();
    this->disableButtons();

    this->ui->copyProgress->setRange(0, this->status->getNumberOfAllFiles());
}

void MainWindow::updateCopyProgress()
{
    this->ui->copyProgress->setValue(this->status->getCopiedNumberFiles());
}

void MainWindow::handleFinishedCopy()
{
    this->enableButtons();
    this->hideElementsBeforeRun();
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

    QObject::connect(this->ui->sourceFilePath, SIGNAL(textChanged(QString)), this, SLOT(sourceFilePathChanged(QString)));
    QObject::connect(this->ui->sourceFilePath, SIGNAL(textChanged(QString)), this, SLOT(checkValidPath(QString)));

    QObject::connect(this->ui->destinationPath, SIGNAL(textChanged(QString)), this, SLOT(destinationPathChanged(QString)));
    QObject::connect(this->ui->destinationPath, SIGNAL(textChanged(QString)), this, SLOT(checkValidPath(QString)));
}

void MainWindow::showLabelsAndProgressBar()
{
    this->ui->allFilesLabel->show();
    this->ui->allFilesValue->show();

    this->ui->allFilesSizeLabel->show();
    this->ui->allFilesSizeValue->show();

    this->ui->copiedFilesLabel->show();
    this->ui->copiedFilesValue->show();

    this->ui->failedCopiedFilesLabel->show();
    this->ui->failedCopiedFilesValue->show();

    this->ui->copyProgress->show();
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

   destinationPathStr = QFileDialog::getExistingDirectory(this,
                                                          tr("Open Directory"),
                                                          "",
                                                          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    this->ui->destinationPath->setText(destinationPathStr);
}

void MainWindow::checkValidPath(const QString &text)
{
    if (!this->pathsAreValid()) {
        this->disableCopyButton();
        return;
    }

    this->enableCopyButton();
}

void MainWindow::setSourcePathAsValid()
{
    this->sourceFilePathIsValid = true;
}

void MainWindow::setSourcePathInvalid()
{
    this->sourceFilePathIsValid = false;
}

bool MainWindow::sourcePathIsValid()
{
    return this->sourceFilePathIsValid;
}

void MainWindow::setDestinationPathAsValid()
{
    this->destinationPathIsValid = true;
}

void MainWindow::setDestinationPathInvalid()
{
    this->destinationPathIsValid = false;
}

bool MainWindow::destinationIsValid()
{
    return this->destinationPathIsValid;
}

void MainWindow::disableButtons()
{
    this->ui->sourceFileButton->setDisabled(true);
    this->ui->destinationButton->setDisabled(true);
    this->disableCopyButton();
}

void MainWindow::enableButtons()
{
    this->ui->sourceFileButton->setEnabled(true);
    this->ui->destinationButton->setEnabled(true);
    this->enableCopyButton();
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

    QObject::connect(worker, SIGNAL(beforeCopy()), this, SLOT(handleBeforeStartCopy()));
    QObject::connect(worker, SIGNAL(changeCopyStatus()), this, SLOT(updateInformationAboutCopyProgress()));
    QObject::connect(worker, SIGNAL(finishedCopy()), this, SLOT(handleFinishedCopy()));

    QObject::connect(&copyThread, SIGNAL(started()), worker, SLOT(startCopy()));

    copyThread.start();
}

void MainWindow::enableCopyButton()
{
    this->ui->startCopyButton->setEnabled(true);
}

void MainWindow::disableCopyButton()
{
    this->ui->startCopyButton->setDisabled(true);
}

QString MainWindow::sourcePath()
{
    return this->sourceFilePathStr;
}

QString MainWindow::destinationPath()
{
    return this->destinationPathStr;
}

void MainWindow::errorPathLabelText(const QString &text)
{
    this->ui->sourcePathError->setText(text);
}

void MainWindow::errorDestinationLabelText(const QString &text)
{
    this->ui->destinationPathError->setText(text);
}

void MainWindow::clearErrorSourcePathLabel()
{
    this->ui->sourcePathError->setText("");
}

void MainWindow::clearErrorDestinationPathLabel()
{
    this->ui->destinationPathError->setText("");
}


bool MainWindow::pathsAreValid()
{
    return this->sourcePathIsValid() && this->destinationIsValid();
}
