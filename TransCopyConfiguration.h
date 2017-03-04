#ifndef TransCopyConfiguration_h
#define TransCopyConfiguration_h

#include "TransCopyConfiguration.h"

#include "Configuration.h"

class TransCopyConfiguration {
public:

    TransCopyConfiguration();

    std::string getFileToParsePath();

    std::string getDestinationPath();

    bool withGui();

    bool isDebug();

    bool pathValidationResult();

    bool fileValidationResult();

    void setConfiguration(Configuration* configuration);

    void pathValidResult(bool result);

    void fileValidResult(bool result);

    bool notyficate();

    void setNotyficate(bool result);

    static TransCopyConfiguration& getConfiguration();

private:
    std::string _fileToParsePath;
    std::string _destinationPath;
    bool _notyficate;
    bool _gui;
    bool _debug;
    bool _pathIsValid;
    bool _fileIsValid;
};

#endif // TransCopyConfiguration_h
