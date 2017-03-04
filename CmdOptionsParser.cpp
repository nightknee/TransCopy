#include "CmdOptionsParser.h"

CmdOptionsParsed* CmdOptionsParser::parseAndGetCmdOptionsValue(int argc, char** argv, std::shared_ptr<CmdOptionsDescription> optionsDesc) {
    po::variables_map cmdOptions;

    CmdOptionsParsed* optionsVM = new CmdOptionsParsed;
    try {
        po::store(po::parse_command_line(argc, argv, optionsDesc->sourceCmdDescription()), cmdOptions);
        po::notify(cmdOptions);

        optionsVM->setSourceParsedOptions(cmdOptions);

        return optionsVM;
    } catch (const po::error &e) {
        optionsDesc->makeAvaibleToDisplay();

        throw new CmdOptionsParserException(e.what());
    }
}