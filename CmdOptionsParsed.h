#ifndef  CMDOPTIONSPARSED_H
#define CMDOPTIONSPARSED_H

#include <boost/program_options.hpp>
#include <string>

#include "CmdOptionsDescription.h"

namespace po = boost::program_options;

typedef std::shared_ptr<po::variables_map> optionsStoreTypePtr;
typedef po::variables_map optionsStoreType;

class CmdOptionsParser;

class CmdOptionsParsed {
    friend class CmdOptionsParser;
public:
    CmdOptionsParsed();
    bool optionExist(const std::string &opt);
    std::string optionStringValue(const std::string &opt);
    int optionIntValue(const std::string &opt);
    void setSourceParsedOptions(optionsStoreType &parsedOptions);
    ~CmdOptionsParsed();
private:
    optionsStoreType vm;
};

#endif // CMDOPTIONSPARSED_H
