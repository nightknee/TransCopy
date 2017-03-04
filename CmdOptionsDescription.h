#ifndef CMDOPTIONS_H
#define CMDOPTIONS_H

#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

typedef std::shared_ptr<po::options_description> optionsDescriptionTypePtr;
typedef po::options_description optionsDescriptionType;

class CmdOptionsParser;

class CmdOptionsDescription {
public:
    CmdOptionsDescription(std::string caption);
    optionsDescriptionType sourceCmdDescription();
    void setOptionToDisplay(std::string option);
    std::string getOptionToDisplay();
    bool displayDiscription();
    void makeAvaibleToDisplay();
private:
    void setDefaultOptions();
    optionsDescriptionTypePtr desc;
    std::string optionToDisplayAllOptions;
    bool availableToDisplay;
};
#endif // CMDOPTIONS_H