#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include "File.h"
#include "Exceptions/FileNotExistException.h"
#include "Exceptions/PathNotExistException.h"

namespace fs = boost::filesystem;

class FileManager
{
public:
	FileManager();
	~FileManager();

	static bool fileExist(std::string filePath);
	static bool isAPath(std::string path);
	static File* createFileObject(std::string filePath);
	static fs::path* createPathObject(std::string path);
	static std::fstream* openFile(File &file,std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
private:
	static File* setBaseInformationToFileObject(File* file);
};

#endif // FILEMANAGER_H
