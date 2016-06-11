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
	this->setSettingsFromArgs(argc,argv);
	
	return 0;
}

void TransCopy::setSettingsFromArgs(int argc,char** argv){
	Configuration *defaultConfiguration = new Configuration;
	string temp_argv;
	for(int i = 0; i < argc ; i++){
		temp_argv = argv[i];
		if(temp_argv == "-p"){			
			defaultConfiguration->playlistPath = argv[i+1];
		}
		else if(temp_argv == "-d"){			
			defaultConfiguration->destinationPath = argv[i+1];
		}
		else if(temp_argv == "-h" || temp_argv == "--help"){			
			this->helpMessage();
		}			
	}
	
	defaultConfiguration->gui = false;
	
	TransCopyConfiguration::getConfiguration().setConfiguration(defaultConfiguration);
	
	delete defaultConfiguration;
}

void TransCopy::showConfiguration(){
	TransCopyConfiguration configuration = TransCopyConfiguration::getConfiguration();
	
	std::cout<<configuration.getDestinationPath()
			 <<endl<<configuration.getPlaylistPath()
			 <<endl<<configuration.withGui()<<endl;
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

void TransCopy::helpMessage(){
	
}