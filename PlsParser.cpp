#include "PlsParser.h"

PlsParser::PlsParser(){
	this->expresion = "^File[0-9]+=";
}

bool PlsParser::parse(std::shared_ptr<File> file){
	std::fstream *f = FileManager::openFile(*file,std::ios_base::in);
	std::string line;
	int i = 0;
	std::string _path;
	while(std::getline(*f,line)){
		if(i <= 1){i++; continue;}
		_path = this->getPath(line);
		try{			
			this->parsedFiles.push_back(FileManager::createFileObject(_path));
		}
		catch(FileNotExistException* e){
			continue;
		}
	}
	
	return true;
}
FileVector* PlsParser::getParsedSongs(){
	return &(this->parsedFiles);
}
std::string PlsParser::getPath(std::string line){
   boost::sregex_token_iterator         // Create an iterator using a
     p(line.begin(), line.end(), this->expresion,-1);  // sequence and that reg exp
   boost::sregex_token_iterator end;    // Create an end-of-reg-exp
                                        // marker
	int i = 0;
	std::string _path;
   while (p != end){
      _path+=*p++;   
   }
	return _path;
}

std::string regexPath(std::string line){
	
}

bool PlsParser::validatePlaylist(){
	
}