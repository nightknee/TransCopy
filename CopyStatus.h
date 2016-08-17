#ifndef COPYSTATUS_H
#define COPYSTATUS_H

#include <boost/cstdint.hpp>

#include "AbstractFileParse.h"

typedef boost::ptr_vector<File> FileVector;
/**
 * @class CopyStatus
 * @file CopyStatus.h
 * @brief Class to storage copy progress. They use singleton patern
 */
class CopyStatus
{
public:
/**
 * @brief  Function to get CopyStatus object
 * @return  Reference to object class
 */
	static CopyStatus& getCopyStatus();
	/**
	 * @brief  Get variable _allFilesSize
	 * @return  Copy of _allFilesSize
	 */
	boost::uintmax_t getAllFilesSize();
	/**
	 * @brief Set _allFilesSize
	 * @param size New _allFilesSize value
	 */
	void setAllFilesSize(boost::uintmax_t size);
	/**
	 * @brief Get variable _copiedFilesSize
	 * @return Copy of _copiedFilesSize
	 */
	boost::uintmax_t getCopiedFilesSize();
	/**
	 * @brief Increase  _copiedFilesSize of value in param
	 * @param size
	 */
	void addCopiedFileSize(boost::uintmax_t size);
	/**
	 * @brief  Get variable _toCopyFileSize
	 * @return  Copy of _toCopyFileSize
	 */
	boost::uintmax_t getToCopyFileSize();
	/**
	 * @brief  Get variable _numberOfAllFiles
	 * @return Copy of _numberOfAllFiles
	 */
	FileVector::size_type getNumberOfAllFiles();
	/**
	 * @brief  Set _numberOfAllFiles value
	 */
	void setNumberOfAllFiles(FileVector::size_type);
	/**
	 * @brief Get variable _copiedNumberFiles
	 * @return Copy of _copiedNumberFiles
	 */
	FileVector::size_type getCopiedNumberFiles();

	void  increaseCopiedNumberFiles();
	
//Private functions:
private:
	CopyStatus();
	~CopyStatus();
	void _setToCopyFileSize(boost::uintmax_t size);
	void  _decreaseToCopyFileSize(boost::uintmax_t size);
//Private variables
private:
	/**
		@biref Size of all files to copy
 */
	boost::uintmax_t _allFilesSize;
	/**
		@biref Size of file still wait to copy
	*/ 
	boost::uintmax_t _toCopyFileSize;
	/**
		@biref Size of files was copied
	*/ 
	boost::uintmax_t _copiedFilesSize;
	/**
		@biref All files to copy
	*/ 
	FileVector::size_type _numberOfAllFiles;
	/**
		@biref Number of files was copied
     */ 
	FileVector::size_type _copiedNumberFiles;	
};

#endif // COPYSTATUS_H
