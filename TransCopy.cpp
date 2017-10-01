#include "TransCopy.h"

TransCopy::TransCopy() {    
    CmdOptionsDescription optionsDescription("Options");
    
    this->cmdDesc = this->setBaseCmdOptionsDescription(optionsDescription);
}

std::shared_ptr<CmdOptionsDescription> TransCopy::setBaseCmdOptionsDescription(CmdOptionsDescription& description) {
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

const std::shared_ptr<CmdOptionsDescription>& TransCopy::getMainDescription() const {
    return this->cmdDesc;
}
