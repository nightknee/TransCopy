#ifndef CMDOPTIONS_H
#define CMDOPTIONS_H

#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

typedef std::shared_ptr<po::options_description> optionsDescriptionTypePtr;
typedef po::options_description optionsDescriptionType;

class CmdOptionsParser;

class CmdOptionsDescription
{
	
	friend class CmdOptionsParser;
	
public:
	CmdOptionsDescription(std::string caption);	
private: 
	void setDefaultOptions();
	optionsDescriptionTypePtr desc;
};

#endif // CMDOPTIONS_H
