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
