#ifndef FileParserContainer_h
#define FileParserContainer_h

#include <map>
#include <string>
#include <memory>

#include "AbstractFileParse.h"
#include "PlsParser.h"
#include "Exceptions/BaseException.h"

typedef std::map<std::string, AbstractFileParse*> filesMap;
typedef std::pair<std::string, AbstractFileParse*> insertedType;

/**
 * @class FileParserContainer
 * @file FileParserContainer.h
 * @brief Storage all file parsers extend AbtractFileParse. Singleton pattern
 */
class FileParserContainer {
public:
    FileParserContainer();
    /**
     * @brief Search matched parser
     * @param fileExtension Extension file to parse
     * @return If function find parser then return patern, otherwise throw NotFoundParserException
     * @throw NotFoundParserException
     */
    AbstractFileParse* findParser(const std::string &fileExtension);
    /**
     * @brief  Return static object of class
     * @return Reference to FileParserContainer object
     */
    static FileParserContainer& getInstance();
    /**
     * @brief Insert new parser
     * @param playlistExtenstion Extenstion which parser can parse
     * @param newParser Pointer to new parser which extends AbstractFileParser
     */
    void insertParser(const std::string &playlistExtenstion, AbstractFileParse* newParser);

private:
    /**
           @brief  All parsers
     */
    filesMap parsers;
};

#endif // PlaylistParserContainer_h
