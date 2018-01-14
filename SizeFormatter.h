#ifndef SIZEFORMATTER_H
#define SIZEFORMATTER_H

class SizeFormatter{
    enum class FormatTo {
        SHORTEST,
        NONE,
        KILOBYTES,
        GIGABYTES
    };
public:
    SizeFormatter();
    SizeFormatter(SizeFormatter::FormatTo format);
    double format(const int &input);
private:
    FormatTo displayFormat;
};

#endif /* SIZEFORMATTER_H */

