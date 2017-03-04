#include "CopyStatus.h"

CopyStatus::CopyStatus() {
    this->_allFilesSize = 0;
    this->_copiedFilesSize = 0;
    this->_toCopyFileSize = 0;
    this->_numberOfAllFiles = 0;
    this->_copiedFilesSize = 0;
}

CopyStatus::~CopyStatus() {
}

CopyStatus& CopyStatus::getCopyStatus() {
    static CopyStatus instance;
    return instance;
}

boost::uintmax_t CopyStatus::getAllFilesSize() {
    return this->_allFilesSize;
}

void CopyStatus::setAllFilesSize(boost::uintmax_t size) {
    this->_allFilesSize = size;
    this->_setToCopyFileSize(this->_allFilesSize);
}

void CopyStatus::_setToCopyFileSize(boost::uintmax_t size) {
    this->_toCopyFileSize = size;
}

boost::uintmax_t CopyStatus::getCopiedFilesSize() {
    return this->_copiedFilesSize;
}

void CopyStatus::addCopiedFileSize(boost::uintmax_t size) {
    this->_copiedFilesSize += size;
    this->_decreaseToCopyFileSize(size);
}

void CopyStatus::_decreaseToCopyFileSize(boost::uintmax_t size) {
    this->_toCopyFileSize -= size;
}

boost::uintmax_t CopyStatus::getToCopyFileSize() {
    return this->_toCopyFileSize;
}

FileVector::size_type CopyStatus::getNumberOfAllFiles() {
    return this->_numberOfAllFiles;
}

void CopyStatus::setNumberOfAllFiles(FileVector::size_type size) {
    this->_numberOfAllFiles = size;
}

FileVector::size_type CopyStatus::getCopiedNumberFiles() {
    return this->_copiedNumberFiles;
}

void CopyStatus::increaseCopiedNumberFiles() {
    this->_copiedNumberFiles++;
}