#ifndef COPYSTATUS_H
#define COPYSTATUS_H

#include <stdint.h>
#include <cstddef>
#include <memory>
#include <string>

#include "SizeFormatter.h"

class CopyHandler;

/**
 * @class CopyStatus
 * @file CopyStatus.h
 * @brief Class to storage copy progress. They use singleton patern
 */
class CopyStatus {
    friend class CopyHandler;
public:
    CopyStatus(SizeFormatter &formatter);
    ~CopyStatus();
    /**
     * @brief  Get variable _allFilesSize
     * @return  Copy of _allFilesSize
     */
    const uintmax_t& getAllFilesSize();    
    
    std::string& getFormattedAllFilesSize();
    
    /**
     * @brief Get variable _copiedFilesSize
     * @return Copy of _copiedFilesSize
     */
    const uintmax_t& getCopiedFilesSize();
    
    std::string& getFormattedCopiedFilesSize();
    
	const size_t& getFailedCopiedFiles();
    /**
     * @brief  Get variable _toCopyFileSize
     * @return  Copy of _toCopyFileSize
     */
    uintmax_t getToCopyFileSize();
    
    std::string& getFormattedToCopyFileSize();
    
    /**
     * @brief  Get variable _numberOfAllFiles
     * @return Copy of _numberOfAllFiles
     */
    const size_t& getNumberOfAllFiles();
    /**
     * @brief Get variable _copiedNumberFiles
     * @return Copy of _copiedNumberFiles
     */
    const size_t& getCopiedNumberFiles();
    
    bool isFinished();
    //Private functions:
private:
    void setToCopyFileSize(uintmax_t &size);
    void decreaseToCopyFileSize(uintmax_t &size);
    /**
     * @brief Set _allFilesSize
     * @param size New _allFilesSize value
     */
    void setAllFilesSize(const uintmax_t& size);
    /**
     * @brief Increase  _copiedFilesSize of value in param
     * @param size
     */
    void addCopiedFileSize(uintmax_t size);
    /**
     * @brief  Set _numberOfAllFiles value
     */
    void setNumberOfAllFiles(const size_t&);
    void increaseCopiedNumberFiles();
    void increaseFailedCopiedNumberFiles();
    void setFinishStatus(bool status);
    //Private variables
private:
    /**
            @biref Size of all files to copy
     */
    uintmax_t allFilesSize;

    std::string allFilesSizeFormatted;

    /**
            @biref Size of file still wait to copy
     */
    uintmax_t toCopyFileSize;

    std::string toCopyFileSizeFormatted;

    /**
            @biref Size of files was copied
     */
    uintmax_t copiedFilesSize;

    std::string copiedFilesSizeFromatted;

    /**
            @biref All files to copy
     */
    size_t numberOfAllFiles;
    /**
            @biref Number of files was copied
     */
    size_t copiedNumberFiles;
    
    size_t failedCopiedNumberFiles;
    
    bool finished;
    
    SizeFormatter formatter;
};

using copyStatusPtr = std::shared_ptr<CopyStatus>;

#endif // COPYSTATUS_H
