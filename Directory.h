#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <boost/filesystem.hpp>

#include "DiskObject.h"
#include "File.h"
#include "Exceptions/PathNotExistException.h"

namespace fs = boost::filesystem;

class Directory : public DiskObject {
public:
    Directory(std::string dirPath);          
    virtual ~Directory();
    static bool isExist(std::string dirPath);
    bool copyFile(File &file);
private:
    std::string prepareNewFilePath(File &file);
};

#endif /* DIRECTORY_H */

