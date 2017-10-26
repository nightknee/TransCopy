#include "Directory.h"
#include "DiskObject.h"

Directory::Directory(const std::string &dirPath) : DiskObject(dirPath) {
    if (!Directory::isExist(dirPath)) {
       throw PathException(this->string() + " path doesn't exist");
    }
}

Directory::~Directory() {}


bool Directory::isExist(const std::string &dirPath) {
    fs::path p(dirPath);
    
    return DiskObject::isExist(dirPath) && fs::is_directory(p);
}       

bool Directory::copyFile(filePtr& file)
{    
    try {
        fs::path p(this->prepareNewFilePath(file));

        fs::copy_file(*file, p);

        return true;
    } catch (fs::filesystem_error) {
        return false;
    }
}

std::string Directory::prepareNewFilePath(filePtr& file) {
    return (this->string() + file->filename().string());
}

const char Directory::getSepratator() {
    return Directory::preferred_separator;
}
