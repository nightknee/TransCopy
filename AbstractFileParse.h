#ifndef AbstractPlaylistParse_h
#define AbstractPlaylistParse_h

#include <string>
#include <vector>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

#include "File.h"
#include "FileManager.h"
#include "CopyStatus.h"

typedef boost::ptr_vector<File> FileVector;

namespace fs = boost::filesystem;

/**
 * @class AbstractFileParse
 * @file AbstractFileParse.h
 * @brief  Abtract class extend with all parsers
 */
class AbstractFileParse {
public:
    virtual bool parse(std::shared_ptr<File> file) = 0;
    virtual FileVector* getParsedSongs() = 0;
    virtual std::string getPath(std::string line) = 0;
    virtual boost::uintmax_t getAllFilesSize() = 0;
protected:
    FileVector _parsedFiles;
    boost::uintmax_t _allFilesSize;
    virtual void _appendToFileSize(boost::uintmax_t value) = 0;
};

#endif // AbstractPlaylistParse
