#include "CmdOptionsParsed.h"

CmdOptionsParsed::CmdOptionsParsed()
{
	this->vm = std::make_shared<po::variables_map>();
}

CmdOptionsParsed::~CmdOptionsParsed()
{
}

bool CmdOptionsParsed::optionExist(const std::string& opt){
	return this->vm->count(opt) ? true : false;
}

std::string CmdOptionsParsed::optionStringValue(const std::string opt){
	return this->vm->operator[](opt).as<std::string>;
}

int CmdOptionsParsed::optionIntValue(const std::string opt){
	return this->vm->operator[](opt).as<int>;
}
