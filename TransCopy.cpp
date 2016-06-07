#include "TransCopy.h"
#include "TransCopyConfiguration.h"

TransCopy::TransCopy()
{	
	this->messageRun();
}

TransCopy::~TransCopy()
{
}

int TransCopy::run(int argc,char** argv){	
	return 0;
}

string TransCopy::Name = "TransCopy";
string TransCopy::Version = "0.01";
string TransCopy::DevName = "Mateusz Karwan";
string TransCopy::Mail = "nightknee@gmail.com";
string TransCopy::GitHub = "https://github.com/nightknee/TransCopy";

void TransCopy::messageRun(){
    cout<<"\t \t \t"<<this->Name<<"\t"<<endl<<endl
        <<"\t \t \t"<<this->Version<<" \t"<<endl<<endl
        <<"\t \t \t"<<this->Mail<<endl<<endl
        <<"\t \t"<< this->GitHub<<endl;
}