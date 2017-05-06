#include "Directory.h"
#include "DiskObject.h"

Directory::Directory(std::string dirPath) : DiskObject(dirPath) {
    if (!Directory::isExist(dirPath)) {
       throw new PathNotExistException(this->string() + " path doesn't exist"); 
    }
}

Directory::~Directory() {}


bool Directory::isExist(std::string dirPath) {
    fs::path p(dirPath);
    
    return DiskObject::isExist(dirPath) && fs::is_directory(p);
}       

bool Directory::copyFile(std::shared_ptr<File> file)
{
    return SysFileManager::copy(file->string(), this->string());
}
