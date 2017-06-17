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
    ParsedFiles* parse(std::shared_ptr<File> file);
    
    std::string parsingFileExtension();
private:
    /**
     * @brief Regex patern to parse path 
     */
    boost::regex expresion;
    /**
     * @brief  Append _allFilesSize
     * @param value 
     */
    void _appendToFileSize(boost::uintmax_t value);
    /**
     * @brief Parse line in file and return full path to ile
     * @param line Content one line in file
     * @return Path ready to set in new File class object
     */
    std::string getPath(std::string line);
};

#endif // PlsParser_h
