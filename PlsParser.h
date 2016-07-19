#ifndef PlsParser_h
#define PlsParser_h

#include "AbstractFileParse.h"


class PlsParser : public AbstractFileParse {
	bool parse(std::shared_ptr<File> file);
	FileVector getParsedSongs();
	std::string getPath(std::string line);
	bool validatePlaylist();
	
};

#endif // PlsParser_h
