#ifndef CMDOPTIONS_H
#define CMDOPTIONS_H

#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

class CmdOptionsDescription : public po::options_description{
public:
    CmdOptionsDescription(const std::string &caption);

};

using cmdOptionsDescriptionPtr = std::unique_ptr<CmdOptionsDescription>;

#endif // CMDOPTIONS_H