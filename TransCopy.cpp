#include "TransCopy.h"

TransCopy::TransCopy() {    
    CmdOptionsDescription optionsDescription("Options");
    
    this->cmdDesc = this->setBaseCmdOptionsDescription(optionsDescription);
}

cmdOptionsDescriptionPtr TransCopy::setBaseCmdOptionsDescription(CmdOptionsDescription& description) {
    description.add_options()
            ("help,h", "Help message")
            ("terminal,t", "Not running with GUI");

    return std::make_unique<CmdOptionsDescription>(description);
}

int TransCopy::run(int argc, char** argv) {
    try {
        this->setSettingsFromArgs(argc, argv);

        if (TransCopyConfiguration::getInstance()->optionExist(TransCopy::OPTION_TERMINAL)) {
            Cmd cmdInstance;

            return cmdInstance.run(argc, argv, this->cmdDesc);
        } else {
            Cmd cmdInstance;

            return cmdInstance.run(argc, argv, this->cmdDesc);
        }
    }
    catch (const BaseException e) {
        MainExceptionHandler::handleException(e);
    } 
    catch (std::exception e) {
        MainExceptionHandler::handleException(e);        
    }
    
    return 0;
}

void TransCopy::setSettingsFromArgs(int argc, char** argv) {
    try {
        CmdOptionsParser::parseCmdOptionsToConfiguration(argc, argv, this->cmdDesc);
    } catch (CmdOptionsParserException e) {

    }
}

const std::string TransCopy::Name = "TransCopy";
const std::string TransCopy::Version = "0.01";
const std::string TransCopy::DevName = "Mateusz Karwan";
const std::string TransCopy::Mail = "nightknee@gmail.com";
const std::string TransCopy::GitHub = "https://github.com/nightknee/TransCopy";

const std::string TransCopy::OPTION_TERMINAL = "terminal";
const std::string TransCopy::OPTION_HELP = "help";
