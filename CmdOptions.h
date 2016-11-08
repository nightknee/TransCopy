#ifndef CMDOPTIONS_H
#define CMDOPTIONS_H

#include <string>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class CmdOptions : public po
{
public:
	CmdOptions(std:::string caption);
	~CmdOptions();
};

#endif // CMDOPTIONS_H
