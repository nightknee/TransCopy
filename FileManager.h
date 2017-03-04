#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#ifdef __linux__
#include "linux/SysFileManager.h"
#elif _WIN32
#include "windows/SysFileManager.h"
#endif

#include <string>
#include <boost/filesystem.hpp>

#include "File.h"
#include "Exceptions/FileNotExistException.h"
#include "Exceptions/PathNotExistException.h"
#include "Exceptions/OpenFileException.h"

namespace fs = boost::filesystem;

/**
 * @class FileManager
 * @file FileManager.h
 * @brief  Class to managment files
 */
class FileManager {
public:
    FileManager();
    ~FileManager();
    /**
     * @brief  Check exist file from filePath param
     * @param filePath Full path to file. Example:
     * E:\Foo\bar.txt -Windows
     * \ home\foo\bar.txt - GNU\Linux
     * @return  If file exist return true
     */
    static bool fileExist(std::string filePath);
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
    static bool isAPath(std::string path);
    /**
     * @brief Create File class object and fill all information about it 
     * @param filePath file path like in FileExist function
     * @return  pointer to new File class object.  If file doesn't exist throw FileNotExistException
     * @throw  FileNotExistException
     */
    static File* createFileObject(std::string filePath);
    /**
     * @brief Create boost::filesystem class object represent path
     * @param path  like in isAPath function
     * @return  pointer to new boost::filesystem class object.  If path doesn't exist throw PathNotExistException
     * @throw  PathNotExistException
     */
    static fs::path* createPathObject(std::string path);
    /**
     * @brief  Open file and return fstream handler to file
     * @param fileOobject of File class
     * @param mode std open file modes
     * @return Pointer to fstream object. If fstream::good() return false then is throwing OpenFileException
     * @throw OpenFileException
     */
    static std::fstream* openFile(File &file, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
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
    static bool copyFile(File sourceFile, std::string destination);
private:
    /**
     * @brief Set base information to File object
     * @param file
     * @return pointer to File object
     */
    static File* _setBaseInformationToFileObject(File* file);
};

#endif // FILEMANAGER_H
