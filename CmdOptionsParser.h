#ifndef CMDOPTIONSPARSER_H
#define CMDOPTIONSPARSER_H

#include <boost/program_options.hpp>

#include "CmdOptionsParserAbstract.h"


namespace po = boost::program_options;

class CmdOptionsParser : public CmdOptionsParserAbstract
{
public:
	CmdOptionsParser();
	void parseAndStoreCmdOptions(int argc,char** argv,CmdOptionsDescriptionAbstract*  desc,CmdOptionsParsedAbstract* vm) ;
};

#endif // CMDOPTIONSPARSER_H
