#include "Directory.h"

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
    this->initLogger();
    
    try {
        fs::path p(this->prepareNewFilePath(file));

        fs::copy_file(*file, p);

        return true;
    } catch (fs::filesystem_error e) {
        LOGE_(LoggerInstances::DIRECTORY) << e.what();        
        
        return false;
    }
}

std::string Directory::prepareNewFilePath(filePtr& file) {
    return (this->string() + file->filename().string());
}

const char Directory::getSepratator() {
    return Directory::preferred_separator;
}

void Directory::initLogger() {
    std::string logFileName = Logger::getLogFile("copied-files-log.txt");         
    plog::init<LoggerInstances::DIRECTORY>(plog::error, logFileName.c_str());
}
