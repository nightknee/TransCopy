#ifndef CMDOPTIONS_H
#define CMDOPTIONS_H

#include <string>
#include <boost/program_options.hpp>

#include "CmdOptionsDescriptionAbstract.h"

namespace po = boost::program_options;

class CmdOptionsDescription :  public CmdOptionsDescriptionAbstract
{
public:
	CmdOptionsDescription(std::string caption);
private: 
	void loadOptions();
	std::shared_ptr<po::options_description> desc;
};

#endif // CMDOPTIONS_H
