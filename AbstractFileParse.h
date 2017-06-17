#ifndef AbstractPlaylistParse_h
#define AbstractPlaylistParse_h

#include <string>

#include "ParsedFiles.h"

/**
 * @class AbstractFileParse
 * @file AbstractFileParse.h
 * @brief  Abtract class extend with all parsers
 */
class AbstractFileParse {
public:
    virtual ParsedFiles* parse(std::shared_ptr<File> file) = 0;
    virtual std::string parsingFileExtension() = 0;
protected:
    std::string extension;
};

#endif // AbstractPlaylistParse
