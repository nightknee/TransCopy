#ifndef CMD_H
#define CMD_H

#include "Ui.h"
#include "CmdOptionsDescription.h"
#include "CmdOptionsParser.h"
#include "Exceptions/NotFoundParserException.h"
#include "Directory.h"
#include "File.h"
#include "ParsedFiles.h"
#include "FileParserContainer.h"
#include "CopyStatus.h"
#include "TransCopy.h"
#include "CmdOutput.h"

class Cmd : public Ui{
public:
    static const std::string OPTION_FILE_PATH;
    static const std::string OPTION_DESTINATION_PATH;
    static const std::string OPTION_NOTIFICATE;           
    
    virtual int run(int argc, char** argv, const CmdOptionsDescriptionPtr &desc) ;
private:
    virtual void setConfigurationFromCmd(int argc, char** argv, const CmdOptionsDescriptionPtr &desc);
    const CmdOptionsDescriptionPtr& getOptionsDescription(const CmdOptionsDescriptionPtr &desc);
    void startCopy();
    const Directory* getDestination();
    const File* getFileToParse();
    const AbstractFileParse* getParser(const FilePtr &fileToParse) const;
    const ParsedFiles* startParse(const AbstractFileParse &parser,const FilePtr &fileToParse) const;
    void copyParsedFiles(const ParsedFiles *files, const DirectoryPtr &destination) const ;
    void copyWithNotificate(const ParsedFiles *parFiles, const DirectoryPtr &destination) const;
    void copyWithoutNotificate(const ParsedFiles *parsedFiles, const DirectoryPtr &destination) const;
    void setCopyStatusValues(const ParsedFiles *parFiles, const ParsedFilesStorage &files) const;
    void showCopyStats() const;    
    bool neededToAddSeparator(const std::string &dirPath);
    void displayOptionsDescription();
    void runMessage();
    CmdOutput out;    
    
    CmdOptionsDescriptionPtr desc;
};

#endif /* CMD_H */

