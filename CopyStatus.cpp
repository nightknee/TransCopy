#include "CopyStatus.h"

CopyStatus::CopyStatus() {
    this->allFilesSize = 0;
    this->copiedFilesSize = 0;
    this->toCopyFileSize = 0;
    this->numberOfAllFiles = 0;
    this->copiedFilesSize = 0;
}

CopyStatus::~CopyStatus() {
}

CopyStatus& CopyStatus::getCopyStatus() {
    static CopyStatus instance;
    
    return instance;
}

uintmax_t CopyStatus::getAllFilesSize() {
    return this->allFilesSize;
}

void CopyStatus::setAllFilesSize(uintmax_t size) {
    this->allFilesSize = size;
    this->setToCopyFileSize(this->allFilesSize);
}

void CopyStatus::setToCopyFileSize(uintmax_t size) {
    this->toCopyFileSize = size;
}

uintmax_t CopyStatus::getCopiedFilesSize() {
    return this->copiedFilesSize;
}

void CopyStatus::addCopiedFileSize(uintmax_t size) {
    this->copiedFilesSize += size;
    this->decreaseToCopyFileSize(size);
}

void CopyStatus::decreaseToCopyFileSize(uintmax_t size) {
    this->toCopyFileSize -= size;
}

uintmax_t CopyStatus::getToCopyFileSize() {
    return this->toCopyFileSize;
}

size_t CopyStatus::getNumberOfAllFiles() {
    return this->numberOfAllFiles;
}

void CopyStatus::setNumberOfAllFiles(size_t size) {
    this->numberOfAllFiles = size;
}

size_t CopyStatus::getCopiedNumberFiles() {
    return this->copiedNumberFiles;
}

void CopyStatus::increaseCopiedNumberFiles() {
    this->copiedNumberFiles++;
}