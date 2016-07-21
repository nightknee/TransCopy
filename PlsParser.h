#ifndef PlsParser_h
#define PlsParser_h

#include "AbstractFileParse.h"

#include <iostream>
#include <string>

class PlsParser : public AbstractFileParse {
public:
	PlsParser();
	bool parse(std::shared_ptr<File> file);
	FileVector* getParsedSongs();
	std::string getPath(std::string line);
	bool validatePlaylist();
private:
	boost::regex expresion;
	
};

#endif // PlsParser_h
