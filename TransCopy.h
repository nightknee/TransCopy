#ifndef TRANSCOPY_H
#define TRANSCOPY_H

#define BOOST_WINDOWS_PATH

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
#include "CopyStatus.h"

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
	void _setSettingsFromArgs(int argc,char** argv);
	Configuration* _parseCmdArgs(int argc,char** argv);
	void _prepareCmdDescription(po::options_description &desc);
	Configuration* _setConfigurationFromCmd(po::variables_map &vm);
	/** end cmd options*/
	
	void _helpMessage();
	void _showConfiguration();	
	void _setParser();
	void _createFileToParseObject();
	void _createPathDestinationObject();
	bool _manageParseFile();
	void _copyParsedFiles();
	void _setCopyStatusValues(FileVector *files);
	void _showCopyStats();

//Private variables	
private:
	std::shared_ptr<File> _fileToParse;
	std::shared_ptr<fs::path> _pathDestination;
	AbstractFileParse* _parser;		
};

#endif // TRANSCOPY_H
