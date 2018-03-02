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

using ShortestSizeType = std::pair<FormatTo, double>;
    
class SizeFormatter{   
public:
    SizeFormatter();
    SizeFormatter(FormatTo format);
    const std::string formatBytes(const uintmax_t bytes);
private:        
    double formatToSize(const uintmax_t bytes);
    ShortestSizeType formatToShortestSize(const uintmax_t bytes);   
    int getMaxLoops();    
    FormatTo getMaxFormat();
    FormatTo getFormatFromLoop(int loop);   
    std::string getSizeName(const FormatTo displayFormat);
    int getPrecision(const FormatTo displayFormat);
    
    FormatTo displayFormat;
    static constexpr int CONVERSION_VALUE = 1000;
};

#endif /* SIZEFORMATTER_H */

