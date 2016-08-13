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
	if(!FileManager::fileExist(filePath)){throw new FileNotExistException(filePath+" file doesn't exist");}
	File *newFile = new File(filePath);
	return FileManager::_setBaseInformationToFileObject(newFile);
}


File* FileManager::_setBaseInformationToFileObject(File* file){
	fs::path p(file->getPath());
	
	std::string _tempPath = file->getPath();

	SysFileManager::preparePath(_tempPath);

	file->setSize(fs::file_size(p));
	file->setExntenstion(p.extension().string());	
	file->setFileName(p.stem().string());
	return file;
}

fs::path* FileManager::createPathObject(std::string path){
	SysFileManager::preparePath(path);
	if(!FileManager::isAPath(path)){throw new PathNotExistException(path+" path doesn't exist");}	
	fs::path *p = new fs::path(path);
	return p;
}

std::fstream* FileManager::openFile(File &file,std::ios_base::openmode mode){
	/**
	* @todo Add exception and check opened file 
	*/
	std::fstream *fileStream = new std::fstream;
	if(!fileStream->good()){throw new OpenFileException("Fail open "+file.getPath()+" file.");}
	
	fileStream->open(file.getPath(),mode);
	return fileStream;
}

bool FileManager::copyFile(File sourceFile,std::string destination){
	return SysFileManager::copy(sourceFile.getPath(),(destination+sourceFile.getFileName()+sourceFile.getExntenstion()));
}