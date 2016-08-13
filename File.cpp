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
void File::setSize(boost::uintmax_t size){
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

boost::uintmax_t File::size(){
	return this->_size;
}

fs::path File::boostPath(){
	return this->_boostPathObject;
}

void File::setBoostPath(fs::path p){
	this->_boostPathObject = p;
}