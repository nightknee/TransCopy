#include "FileManager.h"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

bool FileManager::fileExist(std::string filePath){	
	fs::path p(filePath);
	return fs::exists(p) && fs::is_regular_file(p);
}

bool FileManager::isAPath(std::string path){
	fs::path p(path);
	return fs::exists(p) && fs::is_directory(p);
}

File* FileManager::createFileObject(std::string filePath){
	if(!FileManager::fileExist(filePath)){throw new FileNotExistException;}
	return new File;
}


