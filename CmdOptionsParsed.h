#ifndef CMDOPTIONSPARSED_H
#define CMDOPTIONSPARSED_H

#include "CmdOptionsParsedAbstract.h"

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class CmdOptionsParsed : public CmdOptionsParsedAbstract
{
public:
	CmdOptionsParsed();
	bool optionExist(const std::string& opt);
	~CmdOptionsParsed();
private: 	
	std::shared_ptr<po::variables_map> vm;

};

#endif // CMDOPTIONSPARSED_H
