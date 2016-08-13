#include "TransCopy.h"

TransCopy::TransCopy()
{	
	this->messageRun();
}

TransCopy::~TransCopy()
{
}

int TransCopy::run(int argc,char** argv){	
	try{
		this->_setSettingsFromArgs(argc,argv);
		
		this->_createFileToParseObject();
		
		this->_createPathDestinationObject();
		
		this->_setParser();

		if(this->_manageParseFile()){
			this->_copyParsedFiles();
		}
		
	}
	catch(BaseException *e){
		MainExceptionHandler::handleException(e);
	}
	catch(std::exception *e){
		MainExceptionHandler::handleException(e);
	}
	return 0;
}

void TransCopy::_setSettingsFromArgs(int argc,char** argv){
	Configuration *defaultConfiguration = this->_parseCmdArgs(argc,argv);	
	
	defaultConfiguration->gui = false;
	
	TransCopyConfiguration::getConfiguration().setConfiguration(defaultConfiguration);
	
	delete defaultConfiguration;
}

Configuration* TransCopy::_parseCmdArgs(int argc,char** argv){		
	po::options_description desc("Options");
	
	this->_prepareCmdDescription(desc);	
		
	po::variables_map vm;
	
	try{
		po::store(po::parse_command_line(argc,argv,desc),vm);
		po::notify(vm);			
		
		Configuration *tempConfiguration = this->_setConfigurationFromCmd(vm);
		
		return tempConfiguration;
	
	}catch(const po::error &e){
		if(vm.count("help")){
			std::cout<<desc<<std::endl;			
		}else{
			std::cout<<e.what()<<std::endl;
		}
		return this->_setConfigurationFromCmd(vm);
	}
	
}

Configuration* TransCopy::_setConfigurationFromCmd(po::variables_map &vm){
	Configuration *_tempConfiguration = new Configuration;
	
	if(vm.count("file-path")){
		_tempConfiguration->fileToParsePath = vm["file-path"].as<std::string>();
	}
		
	if(vm.count("destination-path")){
		_tempConfiguration->destinationPath = vm["destination-path"].as<std::string>();
	}
	return _tempConfiguration;
}

void TransCopy::_prepareCmdDescription(po::options_description &desc){
	desc.add_options()
		("help,h","help message")
		("file-path,f",po::value<std::string>()->required(),"Path to list files")
		("destination-path,d",po::value<std::string>()->required(),"Path when copy files");
}

void TransCopy::_showConfiguration(){
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
}


void TransCopy::_helpMessage(){
	
}

void TransCopy::setFileToParse(std::shared_ptr<File> f){
	this->_fileToParse = f;
}

std::shared_ptr<File> TransCopy::getFileToParse(){
	return this->_fileToParse;
}

void TransCopy::_createFileToParseObject(){
	File* file = FileManager::createFileObject(TransCopyConfiguration::getConfiguration().getFileToParsePath());
	this->_fileToParse = std::make_shared<File>(*file);
}

void TransCopy::_createPathDestinationObject(){
	fs::path* path = FileManager::createPathObject(TransCopyConfiguration::getConfiguration().getDestinationPath());
	this->_pathDestination = std::make_shared<fs::path>(*path);
}

void TransCopy::_setParser(){
	this->_parser = FileParserContainer::getInstance().findParser(this->_fileToParse->getExntenstion());
}

bool TransCopy::_manageParseFile(){
	return this->_parser->parse(this->_fileToParse);
}

void TransCopy::_copyParsedFiles(){
	FileVector *files = this->_parser->getParsedSongs();
	
	boost::uintmax_t totalFilesSize = this->_parser->getAllFilesSize();
	
	boost::uintmax_t copiedSize = 0;
	
	boost::uintmax_t toCopyFilesSize = totalFilesSize;

	FileVector::size_type numberAllFiles = files->size();
	
	FileVector::size_type copiedNumberFiles = 0;

	for(FileVector::iterator i = files->begin() ; i != files->end() ; ++i){			
		if(FileManager::copyFile(*i,TransCopyConfiguration::getConfiguration().getDestinationPath())){
			++copiedNumberFiles; copiedSize += i->size(); toCopyFilesSize -= i->size();
		}
	}
}