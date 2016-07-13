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
	try{
		this->setSettingsFromArgs(argc,argv);
		
		this->createFileToParseObject();
		
	}
	catch(BaseException& e){
		MainExceptionHandler::handleException(e);
	}
	catch(std::exception& e){
		MainExceptionHandler::handleException(e);
	}
	return 0;
}

void TransCopy::setSettingsFromArgs(int argc,char** argv){
	Configuration *defaultConfiguration = this->parseCmdArgs(argc,argv);	
	
	defaultConfiguration->gui = false;
	
	TransCopyConfiguration::getConfiguration().setConfiguration(defaultConfiguration);
	
	delete defaultConfiguration;
}

Configuration* TransCopy::parseCmdArgs(int argc,char** argv){		
	po::options_description desc("Options");
	
	this->prepareCmdDescription(desc);	
		
	po::variables_map vm;
	
	try{
		po::store(po::parse_command_line(argc,argv,desc),vm);
		po::notify(vm);			
		
		Configuration *tempConfiguration = this->setConfigurationFromCmd(vm);
		
		return tempConfiguration;
	
	}catch(const po::error &e){
		if(vm.count("help")){
			std::cout<<desc<<std::endl;			
		}else{
			std::cout<<e.what()<<std::endl;
		}
		return this->setConfigurationFromCmd(vm);
	}
	
}

Configuration* TransCopy::setConfigurationFromCmd(po::variables_map &vm){
	Configuration *_tempConfiguration = new Configuration;
	
	if(vm.count("file-path")){
		_tempConfiguration->fileToParsePath = vm["file-path"].as<std::string>();
	}
		
	if(vm.count("destination-path")){
		_tempConfiguration->destinationPath = vm["destination-path"].as<std::string>();
	}
	return _tempConfiguration;
}

void TransCopy::prepareCmdDescription(po::options_description &desc){
	desc.add_options()
		("help,h","help message")
		("file-path,f","Path to list files")
		("destination-path,d","Path his->parser = FileParserContainer::getInstance().findParser(TransCopyConfiguration::getConfiguration())when copy files");
}

void TransCopy::showConfiguration(){
	TransCopyConfiguration configuration = TransCopyConfiguration::getConfiguration();
	
	std::cout<<configuration.getDestinationPath()
			 <<std::endl<<configuration.getFileToParsePath()
			 <<std::endl<<configuration.withGui()<<std::endl;
}

std::string TransCopy::Name = "TransCopy";
std::string TransCopy::Version = "0.01";
std::string TransCopy::DevName = "Mateusz Karwan";
std::string TransCopy::Mail = "nightknee@gmail.com";
std::string TransCopy::GitHub = "https://github.com/nightknee/TransCopy";

void TransCopy::messageRun(){
    std::cout<<"\t \t \t"<<this->Name<<"\t"<<std::endl<<std::endl
        <<"\t \t \t"<<this->Version<<" \t"<<std::endl<<std::endl
        <<"\t \t \t"<<this->Mail<<std::endl<<std::endl
        <<"\t \t"<< this->GitHub<<std::endl;
}Program exited with return code: 0


void TransCopy::helpMessage(){
	
}

void TransCopy::setFileToParse(std::shared_ptr<File> f){
	this->fileToParse = f;
}

std::shared_ptr<File> TransCopy::getFileToParse(){
	return this->fileToParse;
}

void TransCopy::createFileToParseObject(){
	
}

void TransCopy::setParser(){
	
}