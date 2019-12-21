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
#include "CmdOptionsParser.h"
#include "CmdOptionsDescription.h"
#include "CmdOptionsParsed.h"
#include "File.h"
#include "Directory.h"
#include "Cmd.h"
#include "Logger.h"
#include "Gui/qtgui.h"

/**
 * @class TransCopy
 * @file TransCopy.h
 * @brief Main program class
 */
class TransCopy {
public:
    static const std::string OPTION_TERMINAL;
    static const std::string OPTION_HELP;

    //Public functions
    TransCopy();
    /**
     * @brief  Main program function called all function seted variables
     * @param argc From int main()
     * @param argv From int main()
     * @return Result of program
     */
    int run(int argc, char** argv);

    //Public variables: 
    static const std::string Name;
    static const std::string Version;
    static const std::string DevName;
    static const std::string Mail;
    static const std::string GitHub;

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
    cmdOptionsDescriptionPtr setBaseCmdOptionsDescription(CmdOptionsDescription& description);

    void initMainLogger();
    //Private variables	
private:
    cmdOptionsDescriptionPtr cmdDesc;
};

#endif // TRANSCOPY_H
