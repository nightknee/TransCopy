#include "SizeFormatter.h"

SizeFormatter::SizeFormatter() {
    this->displayFormat = FormatTo::SHORTEST;
}

SizeFormatter::SizeFormatter(FormatTo displayFormat) {
    this->displayFormat = displayFormat;
}

const std::string SizeFormatter::formatBytes(const uintmax_t bytes) {
    int loops = static_cast<int>(this->displayFormat);
    
    double formated = bytes;        
    
    for (int i = 0 ; i < loops ; i++) {
        formated = formated / SizeFormatter::CONVERSION_VALUE;
    }
    
    std::ostringstream stream;
    
    stream.precision(3);
    
    stream << formated << this->getSizeName(this->displayFormat);
    
    return stream.str();
}

std::string SizeFormatter::getSizeName(const FormatTo displayFormat) {
    switch(displayFormat) {
        case FormatTo::BYTES: {
            return "B";
            break;
        }
        case FormatTo::KILOBYTES: {
            return "KB";
            break;
        }
        case FormatTo::MEGABYTES: {
            return "MB";
            break;
        }
        case FormatTo::GIGABYTES: {
            return "GB";
            break;
        }
        case FormatTo::TERABYTES: {
            return "TB";
            break;
        }
        default: {
            return "";
            break;
        }
    }
}