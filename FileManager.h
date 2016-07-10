#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager
{
public:
	FileManager();
	~FileManager();

	static bool isFileExist(std::string filePath);
};

#endif // FILEMANAGER_H
