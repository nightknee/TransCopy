#include "Song.h"

Song::Song()
{
}

Song::~Song()
{
}

void Song::setTitle(std::string title){
	this->_title = title;
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
std::string Song::getTitle(){
	return this->_title;
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
