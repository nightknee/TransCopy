#ifndef FileFactory_hpp
#define FileFactory_hpp

#include <string>

#include "File.h"

class FileFactory {
public:
    static filePtr create(const std::string& filePath);
};

#endif /* FileFactory_hpp */
