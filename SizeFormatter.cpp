#include <iomanip>

#include "SizeFormatter.h"

SizeFormatter::SizeFormatter() {
    this->displayFormat = FormatTo::SHORTEST;
}

SizeFormatter::SizeFormatter(FormatTo displayFormat) {
    this->displayFormat = displayFormat;
}

const std::string SizeFormatter::formatBytes(const uintmax_t bytes) {
    double formated;
    std::string sizeName;   
    FormatTo format;
    
    if (this->displayFormat == FormatTo::SHORTEST) {
        ShortestSizeType shortestFormat = this->formatToShortestSize(bytes);
                
        sizeName = this->getSizeName(shortestFormat.first);
        format = shortestFormat.first;
        formated = shortestFormat.second;
    } else {
        formated = this->formatToSize(bytes);
        sizeName = this->getSizeName(this->displayFormat);
        format = this->displayFormat;
    }
    
    std::ostringstream stream;        
    
    stream << std::setprecision(this->getPrecision(format)) << formated << sizeName;
    
    return stream.str();
}

double SizeFormatter::formatToSize(const uintmax_t bytes) {
    int loops = static_cast<int> (this->displayFormat);

    double formated = bytes;

    for (int i = 0; i < loops; i++) {
        formated /= SizeFormatter::CONVERSION_VALUE;
    }
    
    return formated;
}

ShortestSizeType SizeFormatter::formatToShortestSize(const uintmax_t bytes) {
    ShortestSizeType shortestFormat(FormatTo::BYTES, static_cast<double>(bytes));              
    
    for(int i = 1; i < this->getMaxLoops(); i++) {
        if (shortestFormat.first == this->getMaxFormat() || 
                (shortestFormat.second < SizeFormatter::CONVERSION_VALUE && (shortestFormat.second/SizeFormatter::CONVERSION_VALUE < SizeFormatter::CONVERSION_VALUE))) {
            break;
        }        
        
        shortestFormat.first = this->getFormatFromLoop(i);
        shortestFormat.second /= SizeFormatter::CONVERSION_VALUE;        
    }
    
    return shortestFormat;
}

std::string SizeFormatter::getSizeName(const FormatTo displayFormat) {
    switch(displayFormat) {
        case FormatTo::BYTES: {
            return "B";
        }
        case FormatTo::KILOBYTES: {
            return "KB";
        }
        case FormatTo::MEGABYTES: {
            return "MB";
        }
        case FormatTo::GIGABYTES: {
            return "GB";
        }
        case FormatTo::TERABYTES: {
            return "TB";
        }
        default: {
          /**
           * @todo
           * Throw exception 
           */
        }
    }
}


int SizeFormatter::getMaxLoops() {
    return static_cast<int> (FormatTo::TERABYTES);
}
    
FormatTo SizeFormatter::getMaxFormat() {
    return FormatTo::TERABYTES;
}

FormatTo SizeFormatter::getFormatFromLoop(int loop) {
    switch(loop) {
        case static_cast<int> (FormatTo::BYTES): {
            return FormatTo::BYTES;
            break;
        }
        case static_cast<int> (FormatTo::KILOBYTES): {
            return FormatTo::KILOBYTES;
            break;
        }
        case static_cast<int> (FormatTo::MEGABYTES): {
            return FormatTo::MEGABYTES;
            break;
        }
        case static_cast<int> (FormatTo::GIGABYTES): {
            return FormatTo::GIGABYTES;
            break;
        }
        case static_cast<int> (FormatTo::TERABYTES): {
            return FormatTo::TERABYTES;
            break;
        }
        default: {
            /*
             * @todo
             * Throw exception
             */
            break;
        }
    }
}

int SizeFormatter::getPrecision(const FormatTo displayFormat) {
    switch(displayFormat) {
        case FormatTo::BYTES:              
        case FormatTo::KILOBYTES:                   
        case FormatTo::MEGABYTES: 
        case FormatTo::GIGABYTES:                     
        case FormatTo::TERABYTES: 
            return 3;            
            break;        
        default: 
            return 0;            
    }
}
