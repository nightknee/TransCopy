#ifndef AbstractPlaylistParse_h
#define AbstractPlaylistParse_h

#include <string>
#include <fstream>

#include "Songs.h"

class AbstractFileParse  {
	public:
		virtual int parse(std::string filePath) = 0;
		virtual Songs& getParsedSongs() = 0;
		virtual std::string getPath(std::string line) = 0;
		virtual std::string getFileName(std::string line) = 0;
		virtual std::string getExtenstion(std::string fileName) = 0;
		virtual int getFileLenght() = 0;
		virtual bool validatePlaylist() = 0 ;
	protected:
		Songs parsedSongs;
		std::fstream playlistHandler;
};

#endif // AbstractPlaylistParse