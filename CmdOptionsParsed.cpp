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

