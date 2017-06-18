#include "DiskObject.h"

bool DiskObject::isExist(const std::string &objectName)
{
    fs::path p(objectName);
    
    return exists(p);
}
