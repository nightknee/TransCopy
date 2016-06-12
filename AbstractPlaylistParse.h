#ifndef AbstractPlaylistParse_h
#define AbstractPlaylistParse

#include <string>

#include "Songs.h"

class AbstractPlaylistParse  {
	
	virtual int parse(std::string filePath) = 0;
	virtual Songs& getParsedSongs() = 0;
	virtual std::string getPath(std::string line) = 0;
	virtual std::string getFileName(std::string line) = 0;
	virtual std::string getExtenstion(std::string fileName) = 0;
	
private:
	Songs parsedSongs;
};

#endif // AbstractPlaylistParse