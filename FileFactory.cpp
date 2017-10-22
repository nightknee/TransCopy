#include "FileFactory.h"

filePtr FileFactory::create(const std::string& filePath) {
    return filePtr{new File{std::move(filePath)}};
}
