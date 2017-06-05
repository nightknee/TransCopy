#include "TransCopy.h"

TransCopy::TransCopy() {
    this->messageRun();
 
    CmdOptionsDescription optionsDescription("Options");
    this->cmdDesc = this->setBaseCmdOptionsDescription(optionsDescription);   
}

std::shared_ptr<CmdOptionsDescription> TransCopy::setBaseCmdOptionsDescription(CmdOptionsDescription& description)
{    
    description.add_options()
            ("help,h", "Help message")
            ("terminal,t", "Not running with GUI");
    
    return std::make_shared<CmdOptionsDescription>(description);
}

int TransCopy::run(int argc, char** argv) {
    try {
        this->setSettingsFromArgs(argc, argv);

        if (TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_TERMINAL)) {
            Cmd cmdInstance;
            
            return cmdInstance.run(argc, argv, this);
        } else {
            Cmd cmdInstance;
            
            return cmdInstance.run(argc, argv, this);
        }
    } catch (const BaseException *e) {
        std::cout<<*this->cmdDesc<<std::endl;
        
        if (!TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_HELP)) {
            MainExceptionHandler::handleException(e);
        }       
    } catch (std::exception *e) {
        std::cout<<*this->cmdDesc<<std::endl;
        
        if (!TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_HELP)) {
            MainExceptionHandler::handleException(e);
        }
    }
    return 0;
}

void TransCopy::setSettingsFromArgs(int argc, char** argv) {
    try {
           CmdOptionsParser::parseCmdOptionsToConfiguration(argc, argv, this->cmdDesc);
    } catch (const CmdOptionsParserException *e) {
    
    }
}

void TransCopy::cmdCopy() {
    this->createFileToParseObject();

    this->createPathDestinationObject();

    this->setParser();

    if (this->manageParseFile()) {
        this->copyParsedFiles();
    }
}

std::string TransCopy::Name = "TransCopy";
std::string TransCopy::Version = "0.01";
std::string TransCopy::DevName = "Mateusz Karwan";
std::string TransCopy::Mail = "nightknee@gmail.com";
std::string TransCopy::GitHub = "https://github.com/nightknee/TransCopy";

void TransCopy::messageRun() {
    std::cout << "\t \t \t" << this->Name << "\t" << std::endl << std::endl
            << "\t \t \t" << this->Version << " \t" << std::endl << std::endl
            << "\t \t \t" << this->Mail << std::endl << std::endl
            << "\t \t" << this->GitHub << std::endl;
}

void TransCopy::helpMessage() {

}

void TransCopy::setFileToParse(std::shared_ptr<File> f) {
    this->fileToParse = f;
}

std::shared_ptr<File> TransCopy::getFileToParse() {
    return this->fileToParse;
}

void TransCopy::createFileToParseObject() {
    File* file = new File(TransCopyConfiguration::getInstance()->getStringOptionValue(TransCopy::OPTION_FILE_PATH));
    this->fileToParse = std::make_shared<File>(*file);
}

void TransCopy::createPathDestinationObject() {
    Directory* path = new Directory(TransCopyConfiguration::getInstance()->getStringOptionValue(TransCopy::OPTION_DESTINATION_PATH));
    this->pathDestination = std::make_shared<Directory>(*path);
}

void TransCopy::setParser() {
    this->parser = FileParserContainer::getInstance().findParser(this->fileToParse->getExntenstion());
}

bool TransCopy::manageParseFile() {
    return this->parser->parse(this->fileToParse);
}

const std::shared_ptr<CmdOptionsDescription> TransCopy::getMainDescription() {
    return this->cmdDesc;
}

void TransCopy::copyParsedFiles() {
    FileVector *files = this->parser->getParsedSongs();

    this->setCopyStatusValues(files);

    for (FileVector::iterator i = files->begin(); i != files->end(); ++i) {  
        if (this->pathDestination->copyFile(*i)) {
            CopyStatus::getCopyStatus().increaseCopiedNumberFiles();
            CopyStatus::getCopyStatus().addCopiedFileSize(i->size());

            if (TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_NOTIFICATE)) {
                this->showCopyStats();
            }
        }
    }
    std::cout << std::endl;
}

void TransCopy::setCopyStatusValues(FileVector *files) {
    CopyStatus::getCopyStatus().setAllFilesSize(this->parser->getAllFilesSize());
    CopyStatus::getCopyStatus().setNumberOfAllFiles(files->size());
}

void TransCopy::showCopyStats() {
    std::cout << "\r";
    std::cout << "Copied: " << CopyStatus::getCopyStatus().getCopiedNumberFiles() << " of  " << CopyStatus::getCopyStatus().getNumberOfAllFiles() << " files ";
    std::cout << " Copied: " << CopyStatus::getCopyStatus().getCopiedFilesSize() << " of  " << CopyStatus::getCopyStatus().getAllFilesSize() << " bytes ";
    std::cout << "\r";

}