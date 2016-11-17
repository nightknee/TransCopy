#include "CmdOptionsParser.h"

CmdOptionsParser::CmdOptionsParser()
{
}

void CmdOptionsParser::parseAndStoreCmdOptions(int argc,char** argv,
													CmdOptionsDescriptionAbstract*  desc,
													CmdOptionsParsedAbstract* vm)
 {
		po::store(po::parse_command_line(argc,argv,desc),vm);
		po::notify(vm);	
}

