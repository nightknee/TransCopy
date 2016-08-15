#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>

struct Configuration
{
	std::string fileToParsePath;
	std::string destinationPath;
	bool gui;
	bool notyficate;
};
#endif // CONFIGURATION_H
