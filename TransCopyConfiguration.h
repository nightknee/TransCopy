#ifndef TransCopyConfiguration_h
#define TransCopyConfiguration_h

#include <boost/program_options.hpp>

#include "CmdOptionsParser.h"

class TransCopyConfiguration : public boost::program_options::variables_map {
    friend class CmdOptionsParser;
public:
    virtual bool optionExist(const std::string &optionName);  
    
    virtual const std::string& getStringOptionValue(const std::string &optionName);   
    
    virtual const int getIntOptionValue(const std::string &optionName);        
    
    static TransCopyConfiguration* getInstance() {
        static TransCopyConfiguration instance;
        
        return &instance;
    };  
private:    
    static boost::program_options::variables_map* getBoostInstance()
    {                
        return TransCopyConfiguration::getInstance();
    }
};

#endif // TransCopyConfiguration_h
