#ifndef PlsParser_h
#define PlsParser_h

#include <boost/regex.hpp>

#include "AbstractFileParse.h"

/**
 * @class PlsParser
 * @file PlsParser.h
 * @brief Pls files parser
 */
class PlsParser : public AbstractFileParse {
public:
    PlsParser();
    /**
     * @brief Read file and get paths to files
     * @param file
     * @return true if parsing end succesfull
     */
    const ParsedFiles* parse(const filePtr &file) const;
    
    const std::string& parsingFileExtension() const;
private:
    /**
     * @brief Regex patern to parse path 
     */
    boost::regex expresion;
    /**
     * @brief Parse line in file and return full path to ile
     * @param line Content one line in file
     * @return Path ready to set in new File class object
     */
    std::string getPath(const std::string &line) const;
};

#endif // PlsParser_h
