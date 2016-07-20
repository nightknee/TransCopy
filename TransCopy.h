#ifndef TRANSCOPY_H
#define TRANSCOPY_H

#include <iostream>
#include <string>
#include <vector>
#include <boost/program_options.hpp>

#include "TransCopyConfiguration.h"
#include "FileParserContainer.h"
#include "AbstractFileParse.h"
#include "MainExceptionHandler.h"
#include "Exceptions/BaseException.h"
#include "FileManager.h"

namespace po = boost::program_options;

class TransCopy
{
public:
//Public functions
	TransCopy();	
	~TransCopy();
	int run(int argc,char** argv);
	void messageRun();
	std::shared_ptr<File> getFileToParse();
	void setFileToParse(std::shared_ptr<File> f);

//Public variables: 
	static std::string Name;
    static std::string Version;
    static std::string DevName ;
    static std::string Mail;
    static std::string GitHub;
	
//Private functions:
private:
	/**cmd options:*/
	void setSettingsFromArgs(int argc,char** argv);
	Configuration* parseCmdArgs(int argc,char** argv);
	void prepareCmdDescription(po::options_description &desc);
	Configuration *setConfigurationFromCmd(po::variables_map &vm);
	/** end cmd options*/
	
	void helpMessage();
	void showConfiguration();	
	void setParser();
	void createFileToParseObject();
	void createPathDestinationObject();
	void manageParseFile();

//Private variables	
private:
	std::shared_ptr<File> fileToParse;
	std::shared_ptr<fs::path> pathDestination;
	AbstractFileParse *parser;		
};

#endif // TRANSCOPY_H
