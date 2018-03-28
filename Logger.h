#ifndef LOGGER_H
#define LOGGER_H

#pragma warning(disable : 4996)

#include <string>
#include <ctime>

#include <plog/Log.h>

enum LoggerInstances : int {
    DEFAULT = PLOG_DEFAULT_INSTANCE,
    DIRECTORY = 1
};

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

