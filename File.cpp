#include "File.h"
#include <iostream>

File::File(std::string filePath): DiskObject(filePath){    
    if (!File::isExist(filePath)) {
        throw new FileException(filePath + " file doesn't exist");
    }
    
    this->setBaseInformationsAboutFile();
}

File::~File() {}

std::string File::getFileName() {
    return this->fileName;
}

std::string File::getExntenstion() {
    return this->fileExtension;
}

uintmax_t File::size() {
    return this->fileSize;
}

bool File::isExist(std::string fileName) {        
    fs::path p(fileName);
    
    return DiskObject::isExist(fileName) && fs::is_regular_file(p);
}

void File::setBaseInformationsAboutFile() {    
    this->preparePath(this->string());   
              
    this->fileSize = fs::file_size(*this);        
    this->fileExtension = this->extension().string();    
    this->fileName = this->stem().string();
}

std::fstream* File::open(std::ios_base::openmode mode) {
    std::fstream *fileStream = new std::fstream;
    
    fileStream->open(this->string(), mode);
    
    if (!fileStream->good()) {
        throw new FileException("Fail open " + this->getFileName() + " file.");
    }
    
    return fileStream;
}