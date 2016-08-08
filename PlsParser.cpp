#include "PlsParser.h"

PlsParser::PlsParser(){
	this->expresion = "^File[0-9]+=";
	this->allFileSize = 0;
}

bool PlsParser::parse(std::shared_ptr<File> file){
	std::fstream *f = FileManager::openFile(*file,std::ios_base::in);
	
	int i = 0;
	
	std::string line;	
	std::string _path;
	
	while(std::getline(*f,line)){
		if(i <= 1){i++; continue;}
		_path = this->getPath(line);
		try{
			File* file = FileManager::createFileObject(_path);
			this->appendToFileSize(file->size());
			this->parsedFiles.push_back(file);
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
   boost::sregex_token_iterator p(line.begin(), line.end(), this->expresion,-1);  
   
   boost::sregex_token_iterator end;
   
	std::string _path;
	while (p != end){
		_path+=*p++;   
	}
	return _path;
}

unsigned int PlsParser::getAllFilesSize(){
	return this->allFileSize;
}

void PlsParser::appendToFileSize(unsigned int value){
	this->allFileSize += value;
}