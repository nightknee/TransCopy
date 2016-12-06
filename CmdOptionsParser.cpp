#include "CmdOptionsParser.h"

CmdOptionsParser::CmdOptionsParser()
{
}

CmdOptionsParsed* parseAndGetCmdOptionsValue(int argc,char** argv,std::shared_ptr<CmdOptionsDescription>  optionsDesc)
 {
	try{
		po::variables_map cmdOptions;
		
		po::store(po::parse_command_line(argc,argv,optionsDesc->sourceCmdDescription()),cmdOptions);
		po::notify(cmdOptions);
	
		CmdOptionsParsed* optionsVM = new CmdOptionsParsed;		
		optionsVM->setSourceParsedOptions(cmdOptions);
		
		return optionsVM;
	}
	catch(const po::error &e){
		if(optionsVM->optionToDisplayDescriptionExist(optionsDesc)){
			optionsDesc->makeAvaibleToDisplay();
		}
	}
}