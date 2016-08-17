#ifndef PlsParser_h
#define PlsParser_h

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
	bool parse(std::shared_ptr<File> file);
	/**
	 * @brief Return vector with all Files seted parsed file
	 * @return  Pointer to vector File class objects to copy
	 */
	FileVector* getParsedSongs();
	/**
	 * @brief Parse line in file and return full path to ile
	 * @param line Content one line in file
	 * @return Path ready to set in new File class object
	 */
	std::string getPath(std::string line);
	bool validatePlaylist();
	/**
	 * @brief  Return size of all files get it in parsed file
	 * @return  Size of all files
	 */
	boost::uintmax_t getAllFilesSize();
private:
	/**
	* @brief Regex patern to parse path 
	*/
	boost::regex _expresion;
	/**
	 * @brief  Append _allFilesSize
	 * @param value 
	 */
	void _appendToFileSize(boost::uintmax_t value);
};

#endif // PlsParser_h
