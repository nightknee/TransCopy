#ifndef FILE_H
#define FILE_H

#include <string>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

class File
{
public:
	File();
	File(std::string path);
	~File();
	
	void setFileName(std::string fileName);
	void setPath(std::string path);
	void setExntenstion(std::string extension);
	void setSize(unsigned int size);
	void setBoostPath(fs::path p);
	
	std::string getFileName();
	std::string getPath();
	std::string getExntenstion();
	unsigned int size();
	fs::path boostPath();
	
private:
	std::string _fileName;
	std::string _path;
	std::string _extension;
	unsigned int _size;
	fs::path boostPathObject;

};

#endif // FILE_H
