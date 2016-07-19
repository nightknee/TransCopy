#ifndef AbstractPlaylistParse_h
#define AbstractPlaylistParse_h

#include <string>
#include <vector>
#include <boost/ptr_container/ptr_vector.hpp>

#include "File.h"

typedef boost::ptr_vector<File> FileVector;


class AbstractFileParse  {
	public:
		virtual bool parse(std::shared_ptr<File> file) = 0;
		virtual FileVector getParsedSongs() = 0;
		virtual std::string getPath(std::string line) = 0;
		virtual bool validatePlaylist() = 0 ;
	protected:
		FileVector parsedFiles;
};

#endif // AbstractPlaylistParse