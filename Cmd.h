#ifndef CMD_H
#define CMD_H

#include <thread>

#include "Ui.h"
#include "Exceptions/NotFoundParserException.h"
#include "CmdOptionsDescription.h"
#include "CmdOptionsParser.h"
#include "CopyHandler.h"
#include "TransCopy.h"
#include "CmdOutput.h"

class Cmd : public TransCopySpace::Ui{
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
    void setCopyStatusValues(const ParsedFiles *parFiles, const ParsedFilesStorage &files) const;
    bool neededToAddSeparator(const std::string &dirPath);
    void displayOptionsDescription();
    void runMessage();
    CmdOutput out;    
    
    cmdOptionsDescriptionPtr desc;
};

#endif /* CMD_H */

