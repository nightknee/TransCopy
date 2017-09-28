#include "Cmd.h"

int Cmd::run(int argc, char** argv, const CmdOptionsDescriptionPtr &desc) {
    try {
        this->desc = std::move(desc);

        this->setConfigurationFromCmd(argc, argv, desc);

        this->startCopy();
    } 
    catch (CmdOptionsParserException *e) {
        this->displayOptionsDescription();

        if (!TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_HELP)) {
            this->out << e;
        }
    } 
    catch (NotFoundParserException *e) {
        this->displayOptionsDescription();
        this->out << e;
    } 
    catch (PathException *e) {
        this->displayOptionsDescription();
        this->out << e;
    } 
    catch (FileException *e) {
        this->displayOptionsDescription();
        this->out << e;
    } 
    catch (const BaseException *e) {
        this->out << *desc;
        if (!TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_HELP)) {
            this->out << e;
        }
    } 
    catch (std::exception *e) {
        this->out << *desc;
        if (!TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_HELP)) {
            this->out << e;
        }
    }

    return 0;
}

void Cmd::displayOptionsDescription() {
    this->out << *desc;
}

void Cmd::setConfigurationFromCmd(int argc, char** argv, const CmdOptionsDescriptionPtr &desc) {
    CmdOptionsParser::parseCmdOptionsToConfiguration(argc, argv, this->getOptionsDescription(desc));
}

const CmdOptionsDescriptionPtr& Cmd::getOptionsDescription(const CmdOptionsDescriptionPtr &desc) {
    desc->add_options()
            ("file-path,f", po::value<std::string>()->required(), "Path to list files")
            ("destination-path,d", po::value<std::string>()->required(), "Path when copy files")
            ("notificate,n", "Show informations about progress copy");

    return desc;
}

void Cmd::startCopy() {
    const FilePtr fileToParse = std::make_shared<File>(*(this->getFileToParse()));
    const DirectoryPtr destination = std::make_shared<Directory>(*(this->getDestination()));
    const AbstractFileParse *parser = this->getParser(fileToParse);

    const ParsedFiles *files = this->startParse(*parser, fileToParse);

    if (!files->isEmpty()) {
        this->copyParsedFiles(files, destination);
    }

    delete files;
}

const File* Cmd::getFileToParse() {
    File* file = new File(TransCopyConfiguration::getInstance()->getStringOptionValue(Cmd::OPTION_FILE_PATH));

    return file;
}

const Directory* Cmd::getDestination() {
    std::string destination = TransCopyConfiguration::getInstance()->getStringOptionValue(Cmd::OPTION_DESTINATION_PATH);

    if (this->neededToAddSeparator(destination)) {
        destination += Directory::getSepratator();
    }

    Directory* path = new Directory(destination);

    return path;
}

const AbstractFileParse* Cmd::getParser(const FilePtr &fileToParse) const {
    return FileParserContainer::getInstance().findParser(fileToParse->getExntenstion());
}

const ParsedFiles* Cmd::startParse(const AbstractFileParse &parser, const FilePtr &fileToParse) const {
    return parser.parse(fileToParse);
}

void Cmd::copyParsedFiles(const ParsedFiles *files, const DirectoryPtr &destination) const {
    if (TransCopyConfiguration::getInstance()->optionExist(Cmd::OPTION_NOTIFICATE)) {
        this->copyWithNotificate(files, destination);
    } else {
        this->copyWithoutNotificate(files, destination);
    }
}

void Cmd::copyWithNotificate(const ParsedFiles *parFiles, const DirectoryPtr &destination) const {
    ParsedFilesStorage *files = parFiles->getParsedFilesStorage();

    this->setCopyStatusValues(parFiles, *files);

    for (ParsedFilesStorage::iterator i = files->begin(); i != files->end(); ++i) {
        if (destination->copyFile(*i)) {
            CopyStatus::getCopyStatus().increaseCopiedNumberFiles();
            CopyStatus::getCopyStatus().addCopiedFileSize(i->size());

            this->showCopyStats();
        }
    }
    std::cout << std::endl;
}

void Cmd::copyWithoutNotificate(const ParsedFiles *parsedFiles, const DirectoryPtr &destination) const {
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
