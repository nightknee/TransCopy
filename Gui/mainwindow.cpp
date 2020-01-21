#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setLabels();

    this->hideElementsBeforeRun();

    this->initSingalsToSlots();

    this->disableCopyButton();

    qRegisterMetaType<copyStatusPtr>("copyStatusPtr");    

//    this->setFixedSize(MainWindow::WINDOW_WEIGHT,MainWindow::WINDOW_HEIGHT);
}

MainWindow::~MainWindow()
{
    delete ui;

    if (this->copyThread) {
        this->copyThread->quit();
        this->copyThread->wait();
    }
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
    if (!Directory::isExist(text.toStdString())) {
        this->errorDestinationLabelText("Directory doesn't exist");
        this->setDestinationPathInvalid();
        return;
    }

    this->destinationPathStr = this->validDestinationToCopy(text);

    this->setDestinationPathAsValid();
}

void MainWindow::handleBeforeStartCopy()
{
    this->showLabelsAndProgressBar();
    this->disableButtons();


}

void MainWindow::updateCopyProgress(int number)
{
    this->ui->copyProgress->setValue(number);
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

void MainWindow::updateInformationAboutCopyProgress(copyStatusPtr ptr)
{     
//    this->copiedFilesValue = ptr->getFormattedCopiedFilesSize();  

    this->ui->copiedFilesValue->setText(QString::fromUtf8(ptr->getFormattedCopiedFilesSize().c_str()));   

//    this->copiedFilesSizeValue.fromStdString(ptr->getFormattedCopiedFilesSize());
    this->ui->copiedFilesSizeValue->setText(QString::fromUtf8(ptr->getFormattedCopiedFilesSize().c_str()));

//    this->failedCopiedFilesValue.number(ptr->getFailedCopiedFiles());
    this->ui->failedCopiedFilesValue->setText(QString::number(ptr->getFailedCopiedFiles()));   

    this->ui->allFilesSizeValue->setText(QString::fromUtf8(ptr->getFormattedAllFilesSize().c_str()));

    int allFilesNumber = ptr->getNumberOfAllFiles();

    this->ui->copyProgress->setRange(0, allFilesNumber);
    this->updateCopyProgress(ptr->getCopiedNumberFiles());

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
                                                          QFileDialog::ShowDirsOnly);

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

QString* MainWindow::validDestinationToCopy(const QString &destination)
{
    char separator = Directory::getSepratator();
    QString *tempDestination = new QString(destination);

    if (tempDestination->back() != separator) {
        tempDestination->push_back(separator);
    }

    return tempDestination;
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
    QThread *copyThread = new QThread();

    CopyWorker *worker = new CopyWorker(
                this->sourcePath().toStdString(),
                this->destinationPath().toStdString()
            );

    worker->moveToThread(copyThread);

    QObject::connect(worker, &CopyWorker::beforeCopy, this, &MainWindow::handleBeforeStartCopy);
    QObject::connect(worker, &CopyWorker::changeCopyStatus, this, &MainWindow::updateInformationAboutCopyProgress);
    QObject::connect(worker, SIGNAL(finishedCopy()), this, SLOT(handleFinishedCopy()));

    QObject::connect(copyThread, SIGNAL(started()), worker, SLOT(startCopy()));

    this->copyThread = copyThread;

    this->copyThread->start();
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

const QString MainWindow::destinationPath()
{
    return *this->destinationPathStr;
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
