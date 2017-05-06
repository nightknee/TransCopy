#ifndef DISKOBJECT_H
#define DISKOBJECT_H

#ifdef __linux__
#include "linux/SysFileManager.h"
#elif _WIN32
#include "windows/SysFileManager.h"
#endif

#include <boost/filesystem.hpp>
#include <string>

namespace fs = boost::filesystem;

class DiskObject : public fs::path, protected SysFileManager {
public:
    static bool isExist(std::string objectName);
    DiskObject(std::string path): fs::path(path){} 
    virtual ~DiskObject() {}

private:

};

#endif /* DISKOBJECT_H */

