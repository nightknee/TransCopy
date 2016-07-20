#include "FileManager.h"
#include <iostream>
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
	File *newFile = new File(filePath);
	return FileManager::setBaseInformationToFileObject(newFile);
}


File* FileManager::setBaseInformationToFileObject(File* file){
	fs::path p(file->getPath());

	file->setSize(fs::file_size(p));
	file->setExntenstion(p.extension().string());	
	file->setFileName(p.stem().string());
	return file;
}

fs::path* FileManager::createPathObject(std::string path){
	if(!FileManager::isAPath(path)){throw new PathNotExistException;}
	fs::path *p = new fs::path(path);
	return p;
}
