#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <ctime>

#include <plog/Log.h>

class Logger {
public:   
    static std::string getLogFile(std::string fileName) {
        std::time_t result = std::time(nullptr);
        std::ostringstream stream;
        
        stream << std::put_time(std::localtime(&result), "%d-%m-%Y") << "-" << fileName;             
        
        return stream.str();
    }
};

#endif /* LOGGER_H */

