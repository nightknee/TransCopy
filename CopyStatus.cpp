#include "CopyStatus.h"

CopyStatus::CopyStatus(SizeFormatter &formatter) : formatter(std::move(formatter)) {
    this->allFilesSize = 0;
    this->copiedFilesSize = 0;
    this->toCopyFileSize = 0;
    this->numberOfAllFiles = 0;
    this->copiedFilesSize = 0;
    this->copiedNumberFiles = 0;
    this->failedCopiedNumberFiles = 0;
    this->finished = false;    
}

CopyStatus::~CopyStatus() {
}

const uintmax_t& CopyStatus::getAllFilesSize() {
    return this->allFilesSize;
}

std::string& CopyStatus::getFormattedAllFilesSize() {
    this->allFilesSizeFormatted = this->formatter.formatBytes(this->getAllFilesSize());
    return this->allFilesSizeFormatted;
}

void CopyStatus::setAllFilesSize(const uintmax_t &size){     
    this->allFilesSize = size;
    
    this->setToCopyFileSize(this->allFilesSize);
}

void CopyStatus::setToCopyFileSize(uintmax_t &size){
    this->toCopyFileSize = size;
}

const uintmax_t& CopyStatus::getCopiedFilesSize() {
    return this->copiedFilesSize;
}

std::string& CopyStatus::getFormattedCopiedFilesSize() {
    this->copiedFilesSizeFromatted = this->formatter.formatBytes(this->getCopiedFilesSize());

    return this->copiedFilesSizeFromatted;
}

void CopyStatus::addCopiedFileSize(uintmax_t size) {
    this->copiedFilesSize += size;
    this->decreaseToCopyFileSize(size);
}

void CopyStatus::decreaseToCopyFileSize(uintmax_t &size) {
    this->toCopyFileSize -= size;
}

uintmax_t CopyStatus::getToCopyFileSize() {
    return this->toCopyFileSize;
}

std::string& CopyStatus::getFormattedToCopyFileSize() {
    this->toCopyFileSizeFormatted = this->formatter.formatBytes(this->getToCopyFileSize());

    return this->toCopyFileSizeFormatted;
}

const size_t& CopyStatus::getNumberOfAllFiles() {
    return this->numberOfAllFiles;
}

void CopyStatus::setNumberOfAllFiles(const size_t& size) {
    this->numberOfAllFiles = size;
}

const size_t& CopyStatus::getCopiedNumberFiles() {
    return this->copiedNumberFiles;
}

const size_t& CopyStatus::getFailedCopiedFiles() {
    return this->failedCopiedNumberFiles;
}

void CopyStatus::increaseCopiedNumberFiles() {
    this->copiedNumberFiles++;
}

void CopyStatus::increaseFailedCopiedNumberFiles() {
    this->failedCopiedNumberFiles++;
}

bool CopyStatus::isFinished() {
    return this->finished;
}

void CopyStatus::setFinishStatus(bool status) {    
    this->finished = status;
}
