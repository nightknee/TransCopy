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

File* FileManager::createFile(std::string filePath){
	if(!FileManager::fileExist(filePath)){
		/**
		 * @todo throw if set path is not to file
		 */
	}
	return new File;
}


