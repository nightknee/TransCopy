#ifndef CMDOPTIONSPARSEDABSTRACT_H
#define CMDOPTIONSPARSEDABSTRACT_H

#include <string>

class CmdOptionsParsedAbstract
{
public:
	virtual bool optionExist(const std::string& opt) = 0;
};

#endif // CMDOPTIONSPARSEDABSTRACT_H
