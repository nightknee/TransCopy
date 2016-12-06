#include "CmdOptionsParsed.h"

CmdOptionsParsed::CmdOptionsParsed()
{
;
}

CmdOptionsParsed::~CmdOptionsParsed()
{
}

bool CmdOptionsParsed::optionExist(const std::string& opt){
	return this->vm.count(opt) ? true : false;
}

std::string CmdOptionsParsed::optionStringValue(const std::string opt){
	return this->vm[opt].as<std::string>();
}

int CmdOptionsParsed::optionIntValue(const std::string opt){
	return this->vm[opt].as<int>();
}

void CmdOptionsParsed::setSourceParsedOptions(optionsStoreType parsedOptions){
	this->vm = parsedOptions;
}

bool CmdOptionsParsed::optionToDisplayDescriptionExist(std::shared_ptr<CmdOptionsDescription> desc){
	if(this->optionExist(desc->getOptionToDisplay())){
		return true;
	}
	return false;
}