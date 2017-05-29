#include "DiskObject.h"

bool DiskObject::isExist(std::string objectName)
{
    fs::path p(objectName);
    
    return exists(p);
}
