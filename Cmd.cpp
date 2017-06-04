#include "Cmd.h"

int Cmd::run(int argc, char** argv, TransCopy *tr) {
    this->setConfigurationFromCmd(argc, argv, tr);
    
    return 0;
}

void Cmd::setConfigurationFromCmd(int argc, char** argv, TransCopy *tr) {
    CmdOptionsParser::parseCmdOptionsToConfiguration(argc, argv, this->getOptionsDescription(tr->getMainDescription()));
}

std::shared_ptr<CmdOptionsDescription> Cmd::getOptionsDescription(std::shared_ptr<CmdOptionsDescription>  desc) {    
    
    desc->add_options()
            ("file-path,f", po::value<std::string>()->required(), "Path to list files")
            ("destination-path,d", po::value<std::string>()->required(), "Path when copy files")
            ("notificate,n", "Show informations about progress copy");
   
    return desc;
}