#ifndef FILE_H
#define FILE_H

#include <string>

class File
{
public:
	File();
	~File();
	
	void setFileName(std::string fileName);
	void setPath(std::string path);
	void setExntenstion(std::string extension);
	
	std::string getFileName();
	std::string getPath();
	std::string getExntenstion();
	
private:
	std::string _fileName;
	std::string _path;
	std::string _extension;


};

#endif // FILE_H
