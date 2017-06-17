#ifndef CMD_H
#define CMD_H

#include "Ui.h"
#include "CmdOptionsDescription.h"
#include "CmdOptionsParser.h"
#include "Directory.h"
#include "File.h"
#include "ParsedFiles.h"
#include "FileParserContainer.h"
#include "CopyStatus.h"
#include "TransCopy.h"

class Cmd : public Ui{
public:
    const std::string OPTION_FILE_PATH = "file-path";
    const std::string OPTION_DESTINATION_PATH = "destination-path";
    const std::string OPTION_NOTIFICATE = "notificate";
    
    virtual int run(int argc, char** argv, std::shared_ptr<CmdOptionsDescription> desc);
private:
    virtual void setConfigurationFromCmd(int argc, char** argv, std::shared_ptr<CmdOptionsDescription> desc);
    std::shared_ptr<CmdOptionsDescription> getOptionsDescription(std::shared_ptr<CmdOptionsDescription>  desc);
    void startCopy();
    std::shared_ptr<Directory> getDestination();
    std::shared_ptr<File> getFileToParse();
    AbstractFileParse* getParser(std::shared_ptr<File> fileToParse);
    ParsedFiles* startParse(AbstractFileParse* parser, std::shared_ptr<File>);
    void copyParsedFiles(ParsedFiles* files, std::shared_ptr<Directory> destination);
    void copyWithNotificate(ParsedFiles* files, std::shared_ptr<Directory> destination);
    void copyWithoutNotificate(ParsedFiles* files, std::shared_ptr<Directory> destination);
    void setCopyStatusValues(ParsedFiles* parFiles, ParsedFilesStorage *files);
    void showCopyStats();
};

#endif /* CMD_H */

