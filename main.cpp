
#include "TransCopy.h"

const bool DEBUG = true;

int main(int argc, char **argv)
{
	TransCopy *MainTrans = new TransCopy;
	try{
		return MainTrans->run(argc,argv);
	}
	catch(...){
	}
}
