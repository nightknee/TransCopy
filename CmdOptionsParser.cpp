#include "CmdOptionsParser.h"

void CmdOptionsParser::parseCmdOptionsToConfiguration(int argc, char** argv, const std::shared_ptr<CmdOptionsDescription> &optionsDesc) {
    try {               
        
        boost::program_options::variables_map*  map =  TransCopyConfiguration::getBoostInstance();
        
        po::store(po::parse_command_line(argc, argv, *optionsDesc), *map);

        po::notify(*map);
        
    } catch (const po::error &e) {
        throw new CmdOptionsParserException(e.what());
    }
}