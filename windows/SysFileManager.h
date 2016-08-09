#ifndef SYSFILEMANAGER_H
#define SYSFILEMANAGER_H

#include <windows.h>
#include <string>
class SysFileManager
{
public:
	inline bool static copy(std::string sourceFile,std::string destination){
		wchar_t* wSource = new wchar_t[sourceFile.size()];
		wchar_t* wDest = new wchar_t[destination.size()];

		MultiByteToWideChar(CP_ACP, 0, sourceFile.c_str(), -1, wSource, sourceFile.size());
		MultiByteToWideChar(CP_ACP, 0, destination.c_str(), -1, wSource, destination.size());
		return CopyFile(wSource, wDest,0);
	}
};

#endif // SYSFILEMANAGER_H
