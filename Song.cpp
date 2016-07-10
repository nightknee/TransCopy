#include "Song.h"

Song::Song()
{
}

Song::~Song()
{
}
void Song::setAuthor(std::string author){
	this->_author = author;
}

std::string Song::getAuthor(){
	return this->_author;
}
