#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
public:
	Song();
	~Song();
	
	void setFileName(std::string fileName);
	void setPath(std::string path);
	void setExntenstion(std::string extension);
	void setAuthor(std::string author);
	
	std::string getFileName();
	std::string getPath();
	std::string getExntenstion();
	std::string getAuthor();
	
private:
	std::string _fileName;
	std::string _path;
	std::string _extension;
	std::string _author;

};

#endif // SONG_H
