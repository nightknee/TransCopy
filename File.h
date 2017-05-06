#ifndef FILE_H
#define FILE_H

#include "DiskObject.h"
#include "Exceptions/FileException.h"

namespace fs = boost::filesystem;

/**
 * @class File
 * @file File.h
 * @brief  Class represent file in file system
 */
class File : public DiskObject {
public:    
     /**
     * @brief  Check exist file from filePath param
     * @param filePath Full path to file. Example:
     * E:\Foo\bar.txt -Windows
     * \ home\foo\bar.txt - GNU\Linux
     *
     * @return  If file exist return true
     */
    static bool isExist(std::string fileName);
    /**
            @brief  Constructor seted _path value
     */
    /**
     * @brief Create File class object and fill all information about it 
     * @param filePath file path like in FileExist function
     * 
     * @throw  FileException
     */
    File(std::string filePath);
    virtual ~File();               
    
    std::string getFileName();
    std::string getExntenstion();
    uintmax_t size();    
    std::fstream* open(std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);            

private:
    void setBaseInformationsAboutFile();
    /**
            @brief File name without path and extension
     */
    std::string fileName;
    /**
            @brief File extension
     */
    std::string fileExtension;
    /**
            @brief File size in bytes
     */
    uintmax_t fileSize;

};

#endif // FILE_H
