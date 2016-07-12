#ifndef PlsParser_h
#define PlsParser_h

#include <string>

#include "AbstractFileParse.h"


class PlsParser : public AbstractFileParse {
	int parse(std::string filePath);
	Songs& getParsedSongs();
	std::string getPath(std::string line);
	std::string getFileName(std::string line);
	std::string getExtenstion(std::string fileName);
	int getFileLenght();
	bool validatePlaylist();
	
};

#endif // PlsParser_h
