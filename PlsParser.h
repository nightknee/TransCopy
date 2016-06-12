#ifndef PlsParser_h
#define PlsParser_h

#include <string>

#include "AbstractPlaylistParse.h"


class PlsParser : public AbstractPlaylistParse {
	int parse(std::string filePath);
	Songs& getParsedSongs();
	std::string getPath(std::string line);
	std::string getFileName(std::string line);
	std::string getExtenstion(std::string fileName);
	int getFileLenght();
	bool validatePlaylist();
	
};

#endif // PlsParser_h
