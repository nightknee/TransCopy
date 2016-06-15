#ifndef TRANSCOPY_H
#define TRANSCOPY_H

#include <iostream>
#include <string>

#include "TransCopyConfiguration.h"
#include "PlaylistParserContainer.h"
#include "AbstractPlaylistParse.h"

using namespace std;
class TransCopy
{
public:
	TransCopy();	
	~TransCopy();
	int run(int argc,char** argv);
	static string Name;
    static string Version;
    static string DevName ;
    static string Mail;
    static string GitHub;
	void messageRun();
	
private:
	void setSettingsFromArgs(int argc,char** argv);
	void helpMessage();
	void showConfiguration();
	AbstractPlaylistParse *parser;
	
};

#endif // TRANSCOPY_H
