#ifndef CMD_H
#define CMD_H

#include "Ui.h"
#include "CmdOptionsDescription.h"
#include "CmdOptionsParser.h"
#include "Exceptions/NotFoundParserException.h"
#include "Directory.h"
#include "DirectoryFactory.h"
#include "File.h"
#include "FileFactory.h"
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
    
    virtual int run(int argc, char** argv, cmdOptionsDescriptionPtr &desc) ;
private:
    virtual void setConfigurationFromCmd(int argc, char** argv);
    cmdOptionsDescriptionPtr&& addCmdOptions();
    void startCopy();
    const std::string getDirectoryPath();
    const AbstractFileParse* getParser(const filePtr &fileToParse) const;
    const ParsedFiles* startParse(const AbstractFileParse &parser,const filePtr &fileToParse) const;
    void copyParsedFiles(const ParsedFiles *files, const directoryPtr &destination) const ;
    void copyWithNotificate(const ParsedFiles *parFiles, const directoryPtr &destination) const;
    void copyWithoutNotificate(const ParsedFiles *parsedFiles, const directoryPtr &destination) const;
    void setCopyStatusValues(const ParsedFiles *parFiles, const ParsedFilesStorage &files) const;
    void showCopyStats() const;    
    bool neededToAddSeparator(const std::string &dirPath);
    void displayOptionsDescription();
    void runMessage();
    CmdOutput out;    
    
    cmdOptionsDescriptionPtr desc;
};

#endif /* CMD_H */

