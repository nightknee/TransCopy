#include "PlsParser.h"

PlsParser::PlsParser(){
	this->_expresion = "^File[0-9]+=";
	this->_allFileSize = 0;
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
			this->_appendToFileSize(file->size());
			this->_parsedFiles.push_back(file);
		}
		catch(FileNotExistException* e){
			continue;
		}
	}
	
	return true;
}
FileVector* PlsParser::getParsedSongs(){
	return &(this->_parsedFiles);
}
std::string PlsParser::getPath(std::string line){
   boost::sregex_token_iterator p(line.begin(), line.end(), this->_expresion,-1);  
   
   boost::sregex_token_iterator end;
   
	std::string _path;
	while (p != end){
		_path+=*p++;   
	}
	return _path;
}

unsigned int PlsParser::getAllFilesSize(){
	return this->_allFileSize;
}

void PlsParser::_appendToFileSize(unsigned int value){
	this->_allFileSize += value;
}