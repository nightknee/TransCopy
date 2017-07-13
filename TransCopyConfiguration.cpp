#include "TransCopyConfiguration.h"

bool TransCopyConfiguration::optionExist(const std::string &optionName) 
{
    return this->count(optionName) > 0;
}

const std::string& TransCopyConfiguration::getStringOptionValue(const std::string &optionName) {       
    return this->operator [](optionName).as<std::string>();
}

const int TransCopyConfiguration::getIntOptionValue(const std::string &optionName) {
    return this->operator [](optionName).as<int>();
}
