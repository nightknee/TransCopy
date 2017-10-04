#ifndef  CMDOPTIONSPARSER_H
#define CMDOPTIONSPARSER_H

#include <boost/program_options.hpp>

#include "CmdOptionsDescription.h"
#include "Exceptions/CmdOptionsParserException.h"
#include "TransCopyConfiguration.h"

namespace po = boost::program_options;

class CmdOptionsParser {
public:
    static void parseCmdOptionsToConfiguration(int argc, char** argv, const cmdOptionsDescriptionPtr &optionsDesc);    
};

#endif // CMDOPTIONSPARSER_H
