#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <boost/filesystem.hpp>

#include "DiskObject.h"
#include "File.h"
#include "DiskObject.h"
#include "Exceptions/PathException.h"

namespace fs = boost::filesystem;

class Directory : public DiskObject {
public:
    Directory(const std::string &dirPath);          
    virtual ~Directory();
    
     /**
     * @brief  Check exist path in file system
     * @param path Example:
     * E:\Foo\bar.txt - false
     * E:\Foo\ - true
     * E:\Foo- true
     * \ home\foo\bar.txt - false
     *  \ home\foo\ - true
     *  \ home\foo - true
     * @return 
     */
    static bool isExist(const std::string &dirPath);       
       
    static const char getSepratator();
    
      /**
     * @brief Function copied files use native OS function to copy. If os is not define then function use standard functions
     * @param sourceFile Full path to file with path.file name and extenstion. Example:
     * E:\Foo\bar.txt
     * \ home\Foo\bar.txt
     * @param destination Full path to new file destination with path,file name and extension. Example:
     * D:\new_folder\bar.txt
     * \ mount\disk1\new_folder\bar.txt
     * 
     * sourceFile =  E:\Foo\bar.txt		destination= D:\new_folder\bar.txt
     * sourceFile =  \ home\Foo\bar.txt		destination= \ mount\disk1\new_folder\bar.txt
     * 
     * @return true if copied if succesful
     */
    bool copyFile(filePtr& file);
private:
    std::string prepareNewFilePath(filePtr& file);
};

using directoryPtr = std::shared_ptr<Directory>;

#endif /* DIRECTORY_H */

