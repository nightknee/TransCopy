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
		//CopyFile(L"E:\\MUZYKA\\muzyka\\muzyczka\\Acid Drinkers\\2000 - Broken Head\\Acid Drinkers - There's so much hatred in the air.mp3",L"E:\\trs_test\\Acid Drinkers - There's so much hatred in the air.mp3",1 );
		return true;
	}

	inline void static preparePath(std::string& path) {
		boost::algorithm::replace_all(path, "\\", "\\\\");
	}
};

#endif // SYSFILEMANAGER_H
