#include "PlsParser.h"

PlsParser::PlsParser() {
    this->expresion = "^File[0-9]+=";
    this->extension = "pls";
}

ParsedFiles* PlsParser::parse(std::shared_ptr<File> file) {
    std::fstream *f = file->open(std::ios_base::in);

    int i = 0;

    std::string line;
    std::string path;

    ParsedFiles *resultParsingFiles = new ParsedFiles;
    
    while (std::getline(*f, line)) {
        if (i <= 1) {
            i++;
            continue;
        }
        path = this->getPath(line);
        try {
            File* file = new File(path);
            
            resultParsingFiles->addFile(file);            
        } catch (FileException* e) {
            continue;
        }
    }

    f->close();
    
    delete f;
    
    return resultParsingFiles;
}

std::string PlsParser::getPath(std::string line) {
    boost::sregex_token_iterator p(line.begin(), line.end(), this->expresion, -1);

    boost::sregex_token_iterator end;

    std::string _path;
    while (p != end) {
        _path += *p++;
    }
    return _path;
}

std::string PlsParser::parsingFileExtension() {
    return this->extension;
}