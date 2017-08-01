#ifndef DISKOBJECT_H
#define DISKOBJECT_H

#include <boost/filesystem.hpp>
#include <string>

namespace fs = boost::filesystem;

class DiskObject : public fs::path {
public:
    static bool isExist(const std::string &objectName);
    DiskObject(const std::string &path): fs::path(path){} 
    virtual ~DiskObject() {}
};

#endif /* DISKOBJECT_H */

