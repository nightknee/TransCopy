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
    virtual const ParsedFiles* parse(const filePtr &file) const = 0;
    virtual const std::string& parsingFileExtension() const = 0;
protected:
    std::string extension;
};

#endif // AbstractPlaylistParse
