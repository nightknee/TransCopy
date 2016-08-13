#include "CopyStatus.h"
#include <cstdlib> // NULL 

CopyStatus* CopyStatus::ms_instance = NULL;

CopyStatus::CopyStatus()
{
}

CopyStatus::~CopyStatus()
{
}

CopyStatus* CopyStatus::Instance()
{
	if (ms_instance == NULL) {
		ms_instance = new CopyStatus();
	}
	return ms_instance;
}

void CopyStatus::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = NULL;
}

