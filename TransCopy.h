#ifndef TRANSCOPY_H
#define TRANSCOPY_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <boost/program_options.hpp>

#include "TransCopyConfiguration.h"
#include "PlaylistParserContainer.h"
#include "AbstractPlaylistParse.h"
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
	void checkExistingPathAndFile();
	void checkFileToParse();
	void checkPath();

//Private variables	
private:
	std::shared_ptr<File> fileToParse;
	AbstractPlaylistParse *parser;	
	static std::mutex  checkFilesMutex;
};

#endif // TRANSCOPY_H
