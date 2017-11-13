#include "Cmd.h"

int Cmd::run(int argc, char** argv, cmdOptionsDescriptionPtr &desc) {
    try {
        this->runMessage();
        
        this->desc = std::move(desc);               
        
        this->desc = this->addCmdOptions();
        
        this->setConfigurationFromCmd(argc, argv);

        this->startCopy();
    } 
    catch (CmdOptionsParserException e) {
        this->displayOptionsDescription();

        if (!TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_HELP)) {
            this->out << e << CmdOutput::NEW_LINE;
        }
    } 
    catch (NotFoundParserException e) {
        this->displayOptionsDescription();
        this->out << e << CmdOutput::NEW_LINE;
    } 
    catch (PathException e) {
        this->displayOptionsDescription();
        this->out << e << CmdOutput::NEW_LINE;
    } 
    catch (FileException e) {
        this->displayOptionsDescription();
        this->out << e << CmdOutput::NEW_LINE;
    } 
    catch (const BaseException e) {
        this->out << *desc << CmdOutput::NEW_LINE;

        this->out << "Unsupported error. Check log file." << CmdOutput::NEW_LINE;

        throw e;
    } 
    catch (std::exception e) {
        this->out << *desc << CmdOutput::NEW_LINE;
        
        this->out << "Unsupported error. Check log file." << CmdOutput::NEW_LINE;
        
        throw e;
    }

    return 0;
}

void Cmd::displayOptionsDescription() {
    this->out << *desc << CmdOutput::NEW_LINE;
}

void Cmd::setConfigurationFromCmd(int argc, char** argv) {
    CmdOptionsParser::parseCmdOptionsToConfiguration(argc, argv, this->desc);
}

cmdOptionsDescriptionPtr&& Cmd::addCmdOptions() {
    this->desc->add_options()
            ("file-path,f", po::value<std::string>()->required(), "Path to list files")
            ("destination-path,d", po::value<std::string>()->required(), "Path when copy files")
            ("notificate,n", "Show informations about progress copy");

    return std::move(this->desc);
}

void Cmd::startCopy() {
    CopyHandler copyHandler(TransCopyConfiguration::getInstance()->getStringOptionValue(Cmd::OPTION_FILE_PATH), this->getDirectoryPath());
    
    copyStatusPtr copyStats = copyHandler.getCopyStatus();
    
    std::thread t(&CopyHandler::copy, copyHandler);
    
    t.detach();
    
    while (!copyStats->isFinished()) {
        this->out << copyStats;        
    }        
    
    this->out << CmdOutput::NEW_LINE;
}

const std::string Cmd::getDirectoryPath() {
    std::string destination = TransCopyConfiguration::getInstance()->getStringOptionValue(Cmd::OPTION_DESTINATION_PATH);

    if (this->neededToAddSeparator(destination)) {
        destination += Directory::getSepratator();
    }

    return destination;
}

bool Cmd::neededToAddSeparator(const std::string &dirPath) {
    if (dirPath.back() == Directory::preferred_separator) {
        return false;
    }

    return true;
}

const std::string Cmd::OPTION_FILE_PATH = "file-path";
const std::string Cmd::OPTION_DESTINATION_PATH = "destination-path";
const std::string Cmd::OPTION_NOTIFICATE = "notificate";

void Cmd::runMessage() {
    this->out << CmdOutput::TAB << CmdOutput::TAB << CmdOutput::TAB << TransCopy::Name << CmdOutput::TAB << CmdOutput::NEW_LINE << CmdOutput::NEW_LINE
            << CmdOutput::TAB << CmdOutput::TAB << CmdOutput::TAB << TransCopy::Version << CmdOutput::TAB << CmdOutput::NEW_LINE << CmdOutput::NEW_LINE
            << CmdOutput::TAB << CmdOutput::TAB << CmdOutput::TAB << TransCopy::Mail << CmdOutput::NEW_LINE << CmdOutput::NEW_LINE
            << CmdOutput::TAB << CmdOutput::TAB << TransCopy::GitHub << CmdOutput::NEW_LINE;            
}
