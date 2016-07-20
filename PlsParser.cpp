#include "PlsParser.h"

bool PlsParser::parse(std::shared_ptr<File> file){
	std::fstream *f = FileManager::openFile(*file,std::ios_base::in);
	std::string linia;
	while(std::getline(*f,linia)){	
	std::cout<<linia<<std::endl;
	}
	
	
}
FileVector PlsParser::getParsedSongs(){
	
}
std::string PlsParser::getPath(std::string line){
	
}
bool PlsParser::validatePlaylist(){
	
}