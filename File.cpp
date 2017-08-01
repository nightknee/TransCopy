#include "File.h"

File::File(const std::string &filePath): DiskObject(filePath){    
    if (!File::isExist(filePath)) {
        throw new FileException(filePath + " file doesn't exist");
    }
    
    this->setBaseInformationsAboutFile();
}

File::~File() {}

const std::string& File::getFileName() const {
    return this->fileName;
}

const std::string& File::getExntenstion() const {
    return this->fileExtension;
}

uintmax_t File::size() const {
    return this->fileSize;
}

bool File::isExist(const std::string &fileName){        
    fs::path p(fileName);
    
    return DiskObject::isExist(fileName) && fs::is_regular_file(p);
}

void File::setBaseInformationsAboutFile() {    
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