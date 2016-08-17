#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>
/**
 * @class Configuration
 * @file Configuration.h
 * @brief  Struct to set new configuration
 */
struct Configuration
{
	/**
		@brief Path to file from program get path to files
	 */
	std::string fileToParsePath;
	/**
		@brief  Path where files will be copied
	*/
	std::string destinationPath;
	/**
		@brief  If loaded GUI
	*/
	bool gui;
	/**
		@brief  Showing copy progress
	 */
	bool notyficate;
};
#endif // CONFIGURATION_H
