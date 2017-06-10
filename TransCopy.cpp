#include "TransCopy.h"

TransCopy::TransCopy() {
    this->messageRun();
 
    CmdOptionsDescription optionsDescription("Options");
    this->cmdDesc = this->setBaseCmdOptionsDescription(optionsDescription);   
}

std::shared_ptr<CmdOptionsDescription> TransCopy::setBaseCmdOptionsDescription(CmdOptionsDescription& description)
{    
    description.add_options()
            ("help,h", "Help message")
            ("terminal,t", "Not running with GUI");
    
    return std::make_shared<CmdOptionsDescription>(description);
}

int TransCopy::run(int argc, char** argv) {
    try {
        this->setSettingsFromArgs(argc, argv);

        if (TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_TERMINAL)) {
            Cmd cmdInstance;
            
            return cmdInstance.run(argc, argv, this->getMainDescription());
        } else {
            Cmd cmdInstance;
            
            return cmdInstance.run(argc, argv, this->getMainDescription());
        }
    } catch (const BaseException *e) {
        std::cout<<*this->cmdDesc<<std::endl;
        
        if (!TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_HELP)) {
            MainExceptionHandler::handleException(e);
        }       
    } catch (std::exception *e) {
        std::cout<<*this->cmdDesc<<std::endl;
        
        if (!TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_HELP)) {
            MainExceptionHandler::handleException(e);
        }
    }
    return 0;
}

void TransCopy::setSettingsFromArgs(int argc, char** argv) {
    try {
           CmdOptionsParser::parseCmdOptionsToConfiguration(argc, argv, this->cmdDesc);
    } catch (const CmdOptionsParserException *e) {
    
    }
}

std::string TransCopy::Name = "TransCopy";
std::string TransCopy::Version = "0.01";
std::string TransCopy::DevName = "Mateusz Karwan";
std::string TransCopy::Mail = "nightknee@gmail.com";
std::string TransCopy::GitHub = "https://github.com/nightknee/TransCopy";

void TransCopy::messageRun() {
    std::cout << "\t \t \t" << this->Name << "\t" << std::endl << std::endl
            << "\t \t \t" << this->Version << " \t" << std::endl << std::endl
            << "\t \t \t" << this->Mail << std::endl << std::endl
            << "\t \t" << this->GitHub << std::endl;
}

const std::shared_ptr<CmdOptionsDescription> TransCopy::getMainDescription() {
    return this->cmdDesc;
}
