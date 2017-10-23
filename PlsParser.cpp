#include "PlsParser.h"

PlsParser::PlsParser() {
    this->expresion = "^File[0-9]+=";
    this->extension = "pls";
}

const ParsedFiles* PlsParser::parse(const filePtr &file) const{
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
            filePtr file = FileFactory::create(path);
            
            resultParsingFiles->addFile(file);            
        } catch (FileException* e) {
            continue;
        }
    }

    f->close();
    
    delete f;
    
    return resultParsingFiles;
}

std::string PlsParser::getPath(const std::string &line) const{
    boost::sregex_token_iterator p(line.begin(), line.end(), this->expresion, -1);

    boost::sregex_token_iterator end;

    std::string path;
    while (p != end) {
        path += *p++;
    }
    
    return path;
}

const std::string PlsParser::parsingFileExtension() const{
    return "." + this->extension;
}