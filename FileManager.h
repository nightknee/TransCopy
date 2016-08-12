#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#ifdef __linux__
#include "linux/SysFileManager.h"
#elif _WIN32
#include "windows/SysFileManager.h"
#endif

#include <string>
#include <boost/filesystem.hpp>

#include "File.h"
#include "Exceptions/FileNotExistException.h"
#include "Exceptions/PathNotExistException.h"
#include "Exceptions/OpenFileException.h"

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
	static bool copyFile(File sourceFile,std::string destination);
private:
	static File* setBaseInformationToFileObject(File* file);
};

#endif // FILEMANAGER_H
