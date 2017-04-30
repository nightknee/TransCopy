#ifndef CMDOPTIONS_H
#define CMDOPTIONS_H

#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

class CmdOptionsDescription : public po::options_description{
public:
    CmdOptionsDescription(std::string caption);

};
#endif // CMDOPTIONS_H