#ifndef  CMDOPTIONSPARSER_H
#define CMDOPTIONSPARSER_H

#include <boost/program_options.hpp>

#include "CmdOptionsDescription.h"
#include "Exceptions/CmdOptionsParserException.h"
#include "TransCopyConfiguration.h"

namespace po = boost::program_options;

class CmdOptionsParser {
public:
    static void parseCmdOptionsToConfiguration(int argc, char** argv, std::shared_ptr<CmdOptionsDescription> optionsDesc);    
};

#endif // CMDOPTIONSPARSER_H
