#ifndef CMDOPTIONS_H
#define CMDOPTIONS_H

#include <string>
#include <boost/program_options.hpp>

class CmdOptionsDescription;

typedef std::shared_ptr<CmdOptionsDescription> CmdOptionsDescriptionPtr;

namespace po = boost::program_options;

class CmdOptionsDescription : public po::options_description{
public:
    CmdOptionsDescription(const std::string &caption);

};

#endif // CMDOPTIONS_H