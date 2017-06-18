#include "Directory.h"
#include "DiskObject.h"

Directory::Directory(const std::string &dirPath) : DiskObject(dirPath) {
    if (!Directory::isExist(dirPath)) {
       throw new PathException(this->string() + " path doesn't exist"); 
    }
}

Directory::~Directory() {}


bool Directory::isExist(const std::string &dirPath) {
    fs::path p(dirPath);
    
    return DiskObject::isExist(dirPath) && fs::is_directory(p);
}       

bool Directory::copyFile(File &file)
{    
    return SysFileManager::copy(file.string(), this->prepareNewFilePath(file));
}

std::string Directory::prepareNewFilePath(File &file) {
    return (this->string() + file.filename().string());
}
