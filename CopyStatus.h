#ifndef COPYSTATUS_H
#define COPYSTATUS_H

#include <boost/cstdint.hpp>

#include "AbstractFileParse.h"

/**
 * @class CopyStatus
 * @file CopyStatus.h
 * @brief Class to storage copy progress. They use singleton patern
 */
class CopyStatus {
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
    const uintmax_t& getAllFilesSize();
    /**
     * @brief Set _allFilesSize
     * @param size New _allFilesSize value
     */
    void setAllFilesSize(uintmax_t& size);
    /**
     * @brief Get variable _copiedFilesSize
     * @return Copy of _copiedFilesSize
     */
    const uintmax_t& getCopiedFilesSize();
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
    size_t getNumberOfAllFiles();
    /**
     * @brief  Set _numberOfAllFiles value
     */
    void setNumberOfAllFiles(const size_t&);
    /**
     * @brief Get variable _copiedNumberFiles
     * @return Copy of _copiedNumberFiles
     */
    size_t getCopiedNumberFiles();

    void increaseCopiedNumberFiles();

    //Private functions:
private:
    CopyStatus();
    ~CopyStatus();
    void setToCopyFileSize(uintmax_t &size);
    void decreaseToCopyFileSize(uintmax_t &size);
    //Private variables
private:
    /**
            @biref Size of all files to copy
     */
    uintmax_t allFilesSize;
    /**
            @biref Size of file still wait to copy
     */
    uintmax_t toCopyFileSize;
    /**
            @biref Size of files was copied
     */
    uintmax_t copiedFilesSize;
    /**
            @biref All files to copy
     */
    size_t numberOfAllFiles;
    /**
            @biref Number of files was copied
     */
    size_t copiedNumberFiles;
};

#endif // COPYSTATUS_H
