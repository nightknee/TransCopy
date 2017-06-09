#ifndef TRANSCOPY_H
#define TRANSCOPY_H

#define BOOST_WINDOWS_PATH

#include <iostream>
#include <string>
#include <vector>

#include "TransCopyConfiguration.h"
#include "FileParserContainer.h"
#include "AbstractFileParse.h"
#include "MainExceptionHandler.h"
#include "Exceptions/BaseException.h"
#include "CopyStatus.h"
#include "CmdOptionsParser.h"
#include "CmdOptionsDescription.h"
#include "CmdOptionsParsed.h"
#include "File.h"
#include "Directory.h"
#include "Cmd.h"

/**
 * @class TransCopy
 * @file TransCopy.h
 * @brief Main program class
 */
class TransCopy {
public:     
    const std::string OPTION_TERMINAL = "terminal";
    const std::string OPTION_HELP = "help";
    
    //Public functions
    TransCopy();    
    /**
     * @brief  Main program function called all function seted variables
     * @param argc From int main()
     * @param argv From int main()
     * @return Result of program
     */
    int run(int argc, char** argv);
    /**
     * @brief Write message about program,version,author
     */
    void messageRun();
    /**
     * @brief Pointer to File object represent file to parse
     * @return Object File 
     */
    std::shared_ptr<File> getFileToParse();
    void setFileToParse(std::shared_ptr<File> f);

    const std::shared_ptr<CmdOptionsDescription> getMainDescription();
    
    //Public variables: 
    static std::string Name;
    static std::string Version;
    static std::string DevName;
    static std::string Mail;
    static std::string GitHub;

    //Private functions:
private:
    /**cmd options:*/
    /**
     * @brief Set program settings to configuration class  returned from called _parseCmdArgs function
     * @param argc From int main
     * @param argv From int main
     */
    void setSettingsFromArgs(int argc, char** argv);
    /**
     * @brief Set configuration struct with match options 
     * @param vm Map of seted options from cmd
     * @return Object of Configuration structure
     */
    std::shared_ptr<CmdOptionsDescription> setBaseCmdOptionsDescription(CmdOptionsDescription& description);
    
    //Private variables	
private:
    std::shared_ptr<CmdOptionsDescription> cmdDesc;
};

#endif // TRANSCOPY_H
