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
    const filePtr fileToParse = FileFactory::create(TransCopyConfiguration::getInstance()->getStringOptionValue(Cmd::OPTION_FILE_PATH));
    const directoryPtr destination = DirectoryFactory::create(this->getDirectoryPath());
    const AbstractFileParse *parser = this->getParser(fileToParse);

    const ParsedFiles *files = this->startParse(*parser, fileToParse);

    if (!files->isEmpty()) {
        this->copyParsedFiles(files, destination);
    }

    delete files;
}

const std::string Cmd::getDirectoryPath() {
    std::string destination = TransCopyConfiguration::getInstance()->getStringOptionValue(Cmd::OPTION_DESTINATION_PATH);

    if (this->neededToAddSeparator(destination)) {
        destination += Directory::getSepratator();
    }

    return destination;
}

const AbstractFileParse* Cmd::getParser(const filePtr &fileToParse) const {
    return FileParserContainer::getInstance().findParser(fileToParse->getExntenstion());
}

const ParsedFiles* Cmd::startParse(const AbstractFileParse &parser, const filePtr &fileToParse) const {
    return parser.parse(fileToParse);
}

void Cmd::copyParsedFiles(const ParsedFiles *files, const directoryPtr &destination) const {
    if (TransCopyConfiguration::getInstance()->optionExist(Cmd::OPTION_NOTIFICATE)) {
        this->copyWithNotificate(files, destination);
    } else {
        this->copyWithoutNotificate(files, destination);
    }
}

void Cmd::copyWithNotificate(const ParsedFiles *parFiles, const directoryPtr &destination) const {
    ParsedFilesStorage *files = parFiles->getParsedFilesStorage();

    this->setCopyStatusValues(parFiles, *files);

    for (ParsedFilesStorage::iterator i = files->begin(); i != files->end(); ++i) {
        if (destination->copyFile(*i)) {
            CopyStatus::getCopyStatus().increaseCopiedNumberFiles();
            CopyStatus::getCopyStatus().addCopiedFileSize((*i)->size());

            this->showCopyStats();
        }
    }
    std::cout << std::endl;
}

void Cmd::copyWithoutNotificate(const ParsedFiles *parsedFiles, const directoryPtr &destination) const {
    ParsedFilesStorage *files = parsedFiles->getParsedFilesStorage();

    for (ParsedFilesStorage::iterator i = files->begin(); i != files->end(); ++i) {
        destination->copyFile(*i);
    }
    std::cout << std::endl;
}

void Cmd::setCopyStatusValues(const ParsedFiles *parFiles, const ParsedFilesStorage &files) const {
    CopyStatus::getCopyStatus().setAllFilesSize(const_cast<uintmax_t&> (parFiles->size()));
    CopyStatus::getCopyStatus().setNumberOfAllFiles(files.size());
}

void Cmd::showCopyStats() const {
    std::cout << "\r";
    std::cout << "Copied: " << CopyStatus::getCopyStatus().getCopiedNumberFiles() << " of  " << CopyStatus::getCopyStatus().getNumberOfAllFiles() << " files ";
    std::cout << " Copied: " << CopyStatus::getCopyStatus().getCopiedFilesSize() << " of  " << CopyStatus::getCopyStatus().getAllFilesSize() << " bytes ";
    std::cout << "\r";
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
