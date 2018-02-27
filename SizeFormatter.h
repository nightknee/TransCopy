#ifndef SIZEFORMATTER_H
#define SIZEFORMATTER_H

#include <string>
#include <sstream>

enum class FormatTo {
        BYTES = 0,
        KILOBYTES = 1,
        MEGABYTES = 2,        
        GIGABYTES = 3,
        TERABYTES = 4,
        SHORTEST
    };

class SizeFormatter{   
public:
    SizeFormatter();
    SizeFormatter(FormatTo format);
    const std::string formatBytes(const uintmax_t bytes);
private:        
    double formatToSize(const uintmax_t bytes);
    double formatToShortestSize(const uintmax_t bytes);
    
    std::string getSizeName(const FormatTo displayFormat);
    FormatTo displayFormat;
    static const int CONVERSION_VALUE = 1024;
};

#endif /* SIZEFORMATTER_H */

