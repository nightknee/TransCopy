#include "TransCopyConfiguration.h"

bool TransCopyConfiguration::optionExist(std::string optionName) 
{
    return this->count(optionName) > 0;
}

const std::string TransCopyConfiguration::getStringOptionValue(std::string optionName) {       
    return this->operator [](optionName).as<std::string>();
}

const int TransCopyConfiguration::getIntOptionValue(std::string optionName) {
    return this->operator [](optionName).as<int>();
}
