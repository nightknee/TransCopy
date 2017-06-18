#ifndef FILE_H
#define FILE_H

#include "DiskObject.h"
#include "Exceptions/FileException.h"

class File;

namespace fs = boost::filesystem;

typedef std::shared_ptr<File> FilePtr;

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
    static bool isExist(const std::string &fileName);
    /**
            @brief  Constructor seted _path value
     */
    /**
     * @brief Create File class object and fill all information about it 
     * @param filePath file path like in FileExist function
     * 
     * @throw  FileException
     */
    File(const std::string &filePath);
    virtual ~File();               
    
    const std::string& getFileName() const;
    const std::string& getExntenstion() const;
    uintmax_t size() const;    
    
    /**
     * @brief  Open file and return fstream handler to file
     * @param fileOobject of File class
     * @param mode std open file modes
     * @return Pointer to fstream object. If fstream::good() return false then is throwing OpenFileException
     * @throw FileException
     */
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
