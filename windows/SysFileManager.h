#ifndef SYSFILEMANAGER_H
#define SYSFILEMANAGER_H

#include <fstream>
#include <string>
#include <iostream>
#include <windows.h>
#include <boost/algorithm/string/replace.hpp>

class SysFileManager
{
public:
	inline bool static copy(std::string sourceFile,std::string destination){
		std::wstring  wSourceFile = std::wstring(sourceFile.begin(), sourceFile.end());
		std::wstring  wDestination = std::wstring(destination.begin(), destination.end());
		CopyFile(wSourceFile.c_str(),wDestination.c_str(),1 );
		return true;
	}

	inline void static preparePath(std::string& path) {
		boost::algorithm::replace_all(path, "\\", "\\\\");
	}
};

#endif // SYSFILEMANAGER_H
