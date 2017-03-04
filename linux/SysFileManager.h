#ifndef SYSFILEMANAGER_H
#define SYSFILEMANAGER_H

#include <sys/sendfile.h>  // sendfile
#include <fcntl.h>         // open
#include <unistd.h>        // close
#include <sys/stat.h>      // fstat
#include <sys/types.h>
#include <string>

/**
 * @class SysFileManager
 * @file SysFileManager.h
 * @brief  Class copy files use native GNU\Linux functions
 */
class SysFileManager {
public:

    inline bool static copy(std::string sourceFile, std::string destination) {
        int source = open(sourceFile.c_str(), O_RDONLY, 0);
        int dest = open(destination.c_str(), O_WRONLY | O_CREAT, 0644);
        if (source > -1 && dest > -1) {
            struct stat stat_source;
            fstat(source, &stat_source);

            sendfile(dest, source, 0, stat_source.st_size);

            close(source);
            close(dest);
            return true;
        }
        return false;
    }

    /**
     * @brief Is empty beacuse in GNU\Linux is not nessesary to manipulate path
     * @param path
     */
    inline void static preparePath(std::string& path) {
    }
};

#endif // SYSFILEMANAGER_H
