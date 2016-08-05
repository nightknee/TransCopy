#ifndef PlsParser_h
#define PlsParser_h

#include "AbstractFileParse.h"

class PlsParser : public AbstractFileParse {
public:
	PlsParser();
	bool parse(std::shared_ptr<File> file);
	FileVector* getParsedSongs();
	std::string getPath(std::string line);
	bool validatePlaylist();
	int getAllFilesSize();
private:
	boost::regex expresion;
	int appendToFileSize(int value);
};

#endif // PlsParser_h
