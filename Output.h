#ifndef OUTPUTSTREAM_H
#define OUTPUTSTREAM_H

#include <string>

class Output {
public:
    Output& operator<<(const std::string& str) = 0;
private:

};

#endif /* OUTPUTSTREAM_H */

