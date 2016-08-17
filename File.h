#ifndef FILE_H
#define FILE_H

#include <string>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
/**
 * @class File
 * @file File.h
 * @brief  Class represent file in file system
 */
class File
{
public:
	File();
	/**
		@brief  Constructor seted _path value
	*/
	File(std::string path);
	~File();
	
	void setFileName(std::string fileName);
	void setPath(std::string path);
	void setExntenstion(std::string extension);
	void setSize(boost::uintmax_t size);
	void setBoostPath(fs::path p);
	
	std::string getFileName();
	std::string getPath();
	std::string getExntenstion();
	boost::uintmax_t size();
	fs::path boostPath();
	
private:
	/**
		@brief File name without path and extension
	*/
	std::string _fileName;
	/**
		@brief File path with path and extension
	*/
	std::string _path;
	/**
		@brief File extension
	*/
	std::string _extension;
	/**
		@brief File size in bytes
  	*/
	boost::uintmax_t _size;
	/**
		@brief boost::filesystem object
	*/
	fs::path _boostPathObject;

};

#endif // FILE_H
