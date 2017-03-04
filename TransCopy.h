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
#include "FileManager.h"
#include "CopyStatus.h"
#include "CmdOptionsParser.h"
#include "CmdOptionsDescription.h"
#include "CmdOptionsParsed.h"

/**
 * @class TransCopy
 * @file TransCopy.h
 * @brief Main program class
 */
class TransCopy {
public:
    //Public functions
    TransCopy();
    ~TransCopy();
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
     * @brief  Parsing arguments from cmd and return configuration object to set
     * @param argc From int main
     * @param argv From int main
     * @return  Configuration object
     */
    CmdOptionsParsed* parseCmdArgs(int argc, char** argv);
    /**
     * @brief Set configuration struct with match options 
     * @param vm Map of seted options from cmd
     * @return Object of Configuration structure
     */
    Configuration* setConfigurationFromCmd(CmdOptionsParsed* parsedOptions);
    /** end cmd options*/

    void helpMessage();
    void showConfiguration();
    /**
     * @brief Set finded parser object after validate _fileToParse
     */
    void setParser();
    /**
     * @brief Create File object in FileManager and set pointer to _fileToParse
     */
    void createFileToParseObject();
    /**
     * @brief Create boost::filesystem object in FileManager and set pointer to _pathDestination
     */
    void createPathDestinationObject();
    /**
     * @brief Begin parsing file
     * @return true if parsing end succesful or false
     */
    bool manageParseFile();
    /**
     * @brief Copied all files to destination path using FileManager function.
     *			 	Set variables for CopyStatus class
     */
    void copyParsedFiles();
    /**
     * @brief Set initial values to CopyStatus class to track copy progress
     * @param files Vector of all parsed files
     */
    void setCopyStatusValues(FileVector *files);
    /**
     * @brief Show copy progress up to date if TransCopyConfiguration::notyficate = true
     */
    void showCopyStats();
    /**
     * @brief  Run copy funciotns and display information in command line
     */
    void cmdCopy();

    //Private variables	
private:
    /**
     * @brief Object of File class to parse
     */
    std::shared_ptr<File> fileToParse;
    /**
     * @brief Object of boost::filesystem class to destination path
     */
    std::shared_ptr<fs::path> pathDestination;
    /** 
     * @brief Pointer to parser avaible to _fileToParse
     */
    AbstractFileParse* parser;

    std::shared_ptr<CmdOptionsDescription> cmdDesc;
};

#endif // TRANSCOPY_H
