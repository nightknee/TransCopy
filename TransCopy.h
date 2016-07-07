#ifndef TRANSCOPY_H
#define TRANSCOPY_H

#include <iostream>
#include <string>
#include <vector>
#include <boost/program_options.hpp>

#include "TransCopyConfiguration.h"
#include "PlaylistParserContainer.h"
#include "AbstractPlaylistParse.h"
#include "MainExceptionHandler.h"
#include "Exceptions/BaseException.h"

namespace po = boost::program_options;

class TransCopy
{
public:
	TransCopy();	
	~TransCopy();
	int run(int argc,char** argv);
	static std::string Name;
    static std::string Version;
    static std::string DevName ;
    static std::string Mail;
    static std::string GitHub;
	void messageRun();
	
private:
	/**cmd options:*/
	void setSettingsFromArgs(int argc,char** argv);
	Configuration* parseCmdArgs(int argc,char** argv);
	void prepareCmdDescription(po::options_description &desc);
	Configuration *setConfigurationFromCmd(po::variables_map &vm);
	/** end cmd options*/
	
	void helpMessage();
	void showConfiguration();
	AbstractPlaylistParse *parser;
	
};

#endif // TRANSCOPY_H
