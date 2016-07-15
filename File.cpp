#include "File.h"

File::File()
{
}

File::File(std::string path){
	this->setPath(path);
}

File::~File()
{
}

void File::setFileName(std::string fileName){
	this->_fileName = fileName;
}
void File::setPath(std::string path){
	this->_path = path;
}
void File::setExntenstion(std::string extension){
	this->_extension = extension;
}
void File::setSize(unsigned int size){
	this->_size = size;
}


std::string File::getFileName(){
	return this->_fileName;
}
std::string File::getPath(){
	return this->_path;
}
std::string File::getExntenstion(){
	return this->_extension;
}

unsigned int File::size(){
	return this->_size;
}

fs::path File::boostPath(){
	return this->boostPathObject;
}

void File::setBoostPath(fs::path p){
	this->boostPathObject = p;
}