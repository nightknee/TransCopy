#include "CmdOptionsDescription.h"

CmdOptionsDescription::CmdOptionsDescription(std::string caption) 
{
		this->availableToDisplay = false;
		
		this->optionToDisplayAllOptions = "";
		
		this->desc = std::make_shared<po::options_description>(caption);
		
		this->setDefaultOptions();
}

void CmdOptionsDescription::setDefaultOptions(){
	this->desc->add_options()
		("help,h","Help message")
		("file-path,f",po::value<std::string>()->required(),"Path to list files")
		("destination-path,d",po::value<std::string>()->required(),"Path when copy files")
		("notyficate,n","Show informations about progress copy")
		("terminal,t","Not running with GUI");
}

optionsDescriptionType CmdOptionsDescription::sourceCmdDescription(){
	optionsDescriptionType tempCmdOptions = *this->desc;
	return tempCmdOptions;
}

void CmdOptionsDescription::setOptionToDisplay(std::string option){
	this->optionToDisplayAllOptions = option;
}

std::string CmdOptionsDescription::getOptionToDisplay(){
	return this->optionToDisplayAllOptions;
}

bool CmdOptionsDescription::displayDiscription(){
	return this->availableToDisplay;
}

void CmdOptionsDescription::makeAvaibleToDisplay(){
	this->availableToDisplay = true;
}