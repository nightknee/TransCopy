#include "DirectoryFactory.h"

directoryPtr DirectoryFactory::create(const std::string& directoryPath) {
    return directoryPtr{new Directory{std::move(directoryPath)}};
}
