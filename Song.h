#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
public:
	Song();
	~Song();
	
	void setTitle(std::string title);
	void setPath(std::string path);
	void setExntenstion(std::string extension);
	void setAuthor(std::string author);
	
	std::string getTitle();
	std::string getPath();
	std::string getExntenstion();
	std::string getAuthor();
	
private:
	std::string _title;
	std::string _path;
	std::string _extension;
	std::string _author;

};

#endif // SONG_H
