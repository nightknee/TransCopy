#ifndef  CMDOPTIONSPARSED_H
#define CMDOPTIONSPARSED_H

#include <boost/program_options.hpp>

namespace po = boost::program_options;

typedef std::shared_ptr<po::variables_map> optionsStoreTypePtr;
typedef po::variables_map optionsStoreType;

class CmdOptionsParser;

class CmdOptionsParsed 
{
friend class CmdOptionsParser;
public:
	CmdOptionsParsed();
	bool optionExist(const std::string& opt);
	~CmdOptionsParsed();
private: 	
	optionsStoreTypePtr vm;

};

#endif // CMDOPTIONSPARSED_H
