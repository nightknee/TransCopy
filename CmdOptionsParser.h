#ifndef  CMDOPTIONSPARSER_H
#define CMDOPTIONSPARSER_H

#include <boost/program_options.hpp>

#include "CmdOptionsParsed.h"
#include "CmdOptionsDescription.h"

namespace po = boost::program_options;

class CmdOptionsParser 
{
public:
	CmdOptionsParser();
	static CmdOptionsParsed* parseAndGetCmdOptionsValue(int argc,char** argv,std::shared_ptr<CmdOptionsDescription>  optionsDesc) ;	
};

#endif // CMDOPTIONSPARSER_H
