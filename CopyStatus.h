#ifndef COPYSTATUS_H
#define COPYSTATUS_H

#include <boost/cstdint.hpp>

#include "AbstractFileParse.h"

typedef boost::ptr_vector<File> FileVector;

class CopyStatus
{
public:
	static CopyStatus& getCopyStatus();
	
	boost::uintmax_t getAllFilesSize();
	void setAllFilesSize(boost::uintmax_t size);
	
	boost::uintmax_t getCopiedFilesSize();
	void addCopiedFileSize(boost::uintmax_t size);
	
	boost::uintmax_t getToCopyFileSize();
	
	FileVector::size_type getNumberOfAllFiles();
	void setNumberOfAllFiles(FileVector::size_type);
	
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
	//Size of all files to copy
	boost::uintmax_t _allFilesSize;
	//Size of file still wait to copy
	boost::uintmax_t _toCopyFileSize;
	//Size of files was copied
	boost::uintmax_t _copiedFilesSize;
	//All files to copy
	FileVector::size_type _numberOfAllFiles;
	//Number of files was copied
	FileVector::size_type _copiedNumberFiles;	
};

#endif // COPYSTATUS_H
