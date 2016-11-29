#include "CmdOptionsParser.h"

CmdOptionsParser::CmdOptionsParser()
{
}

CmdOptionsParsed* parseAndGetCmdOptionsValue(int argc,char** argv,std::shared_ptr<CmdOptionsDescription>  optionsDesc)
 {
		po::variables_map cmdOptions;
		
		po::store(po::parse_command_line(argc,argv,optionsDesc->desc),cmdOptions);
		po::notify(cmdOptions);
	
		CmdOptionsParsed* optionsVM = new CmdOptionsParsed;
		optionsVM->vm = cmdOptions;
		return optionsVM;
}

