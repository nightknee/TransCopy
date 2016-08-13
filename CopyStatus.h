#ifndef COPYSTATUS_H
#define COPYSTATUS_H

class CopyStatus
{
	static CopyStatus* ms_instance;

public:
	static CopyStatus* Instance();
	static void Release();

private:
	CopyStatus();
	~CopyStatus();

};

#endif // COPYSTATUS_H
