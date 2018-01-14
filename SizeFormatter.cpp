#include "SizeFormatter.h"

SizeFormatter::SizeFormatter() {
    this->displayFormat = SizeFormatter::FormatTo::SHORTEST;
}

SizeFormatter::SizeFormatter(SizeFormatter::FormatTo displayFormat) {
    this->displayFormat = displayFormat;
}

double SizeFormatter::format(const int &input) {
    double d = 1.421;
    return d;
}
