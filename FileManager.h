#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <boost/filesystem.hpp>

#include "File.h"
#include "Exceptions/FileNotExistException.h"

namespace fs = boost::filesystem;

class FileManager
{
public:
	FileManager();
	~FileManager();

	static bool fileExist(std::string filePath);
	static File* createFileObject(std::string filePath);
};

#endif // FILEMANAGER_H
