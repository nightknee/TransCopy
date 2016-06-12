#include "Song.h"

Song::Song()
{
}

Song::~Song()
{
}

void Song::setFileName(std::string fileName){
	this->_fileName = fileName;
}
void Song::setPath(std::string path){
	this->_path = path;
}
void Song::setExntenstion(std::string extension){
	this->_extension = extension;
}
void Song::setAuthor(std::string author){
	this->_author = author;
}
std::string Song::getFileName(){
	return this->_fileName;
}
std::string Song::getPath(){
	return this->_path;
}
std::string Song::getExntenstion(){
	return this->_extension;
}
std::string Song::getAuthor(){
	return this->_author;
}
