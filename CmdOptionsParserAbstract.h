#ifndef CMDOPTIONSPARSERABSTRACT_H
#define CMDOPTIONSPARSERABSTRACT_H

#include "CmdOptionsDescriptionAbstract.h"
#include "CmdOptionsParsedAbstract.h"

class CmdOptionsParserAbstract
{
public:
	virtual void parseAndStoreCmdOptions(int argc,char** argv,CmdOptionsDescriptionAbstract*  desc,CmdOptionsParsedAbstract* vm) = 0;
};

#endif // CMDOPTIONSPARSERABSTRACT_H
