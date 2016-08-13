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
	boost::uintmax_t getAllFilesSize();
private:
	boost::regex _expresion;
	void _appendToFileSize(boost::uintmax_t value);
};

#endif // PlsParser_h
