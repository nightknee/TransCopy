#ifndef DirectoryFactory_hpp
#define DirectoryFactory_hpp

#include <string>

#include "Directory.h"

class DirectoryFactory {
public:
    static directoryPtr create(const std::string& directoryPath);
};

#endif /* DirectoryFactory_hpp */
