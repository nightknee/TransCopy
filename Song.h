#ifndef SONG_H
#define SONG_H

#include "File.h"

class Song : public File
{
public:
	Song();
	~Song();
	
	void setAuthor(std::string author);
	
	std::string getAuthor();
	
private:
	std::string _author;

};

#endif // SONG_H
