#ifndef AbstractParse_h
#define AbstractParse_h

#include <string>

#include "Songs.h"

class AbstractParse  {
	
	virtual int parse(std::string filePath) = 0;
	virtual Songs& getParsedSongs() = 0;
	
private:
	Songs parsedSongs;
};

#endif // AbstractParse_h