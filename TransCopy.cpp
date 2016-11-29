#include "TransCopy.h"

TransCopy::TransCopy()
{
	this->cmdDesc = std::make_shared<CmdOptionsDescription>("Options");	
	
	this->messageRun();

}

TransCopy::~TransCopy(){}

int TransCopy::run(int argc,char** argv){	
	try{
		this->_setSettingsFromArgs(argc,argv);
		
		if(TransCopyConfiguration::getConfiguration().withGui()){
			
		}else{
			this->_cmdCopy();
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

void TransCopy::_cmdCopy(){
	this->_createFileToParseObject();
		
	this->_createPathDestinationObject();
		
	this->_setParser();

	if(this->_manageParseFile()){
		this->_copyParsedFiles();
	}
}

void TransCopy::_setSettingsFromArgs(int argc,char** argv){
	try{
		CmdOptionsParsed* parsedOptions = this->_parseCmdArgs(argc,argv);	
		
		this->_setConfigurationFromCmd(parsedOptions);
		
		defaultConfiguration->gui = false;
		
		TransCopyConfiguration::getConfiguration().setConfiguration(defaultConfiguration);
		
		delete defaultConfiguration;
	}catch(const po::error &e){
		if(vm.count("help")){
			std::cout<<desc<<std::endl;	
			throw new BaseException;
		}else{
			std::cout<<e.what()<<std::endl;
		}
		return this->_setConfigurationFromCmd(vm);
	}
}

CmdOptionsParsed* TransCopy::_parseCmdArgs(int argc,char** argv){		
		return CmdOptionsParser::parseAndGetCmdOptionsValue(argc,argv,this->cmdDesc);		
}

Configuration* TransCopy::_setConfigurationFromCmd(po::variables_map &vm){
	Configuration *_tempConfiguration = new Configuration;
	
	if(vm.count("file-path")){
		_tempConfiguration->fileToParsePath = vm["file-path"].as<std::string>();
	}
		
	if(vm.count("destination-path")){
		_tempConfiguration->destinationPath = vm["destination-path"].as<std::string>();
	}
	if(vm.count("notyficate")){
		_tempConfiguration->notyficate = true;
	}
	if(vm.count("terminal")){
		_tempConfiguration->gui = false;
	}
	return _tempConfiguration;
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
	
	this->_setCopyStatusValues(files);
	
	for(FileVector::iterator i = files->begin() ; i != files->end() ; ++i){			
		if(FileManager::copyFile(*i,TransCopyConfiguration::getConfiguration().getDestinationPath())){
			CopyStatus::getCopyStatus().increaseCopiedNumberFiles();
			CopyStatus::getCopyStatus().addCopiedFileSize( i->size());
			
			if(TransCopyConfiguration::getConfiguration().notyficate()){
				this->_showCopyStats();
			}
		}
	}
	std::cout<<std::endl;
}

void TransCopy::_setCopyStatusValues(FileVector *files){
	CopyStatus::getCopyStatus().setAllFilesSize( this->_parser->getAllFilesSize());
	CopyStatus::getCopyStatus().setNumberOfAllFiles(files->size());
}

void TransCopy::_showCopyStats(){
	std::cout<<"\r";
	std::cout<<"Copied: "<<CopyStatus::getCopyStatus().getCopiedNumberFiles()<<" of  "<<CopyStatus::getCopyStatus().getNumberOfAllFiles()<<" files ";
	std::cout<<" Copied: "<<CopyStatus::getCopyStatus().getCopiedFilesSize()<<" of  "<<CopyStatus::getCopyStatus().getAllFilesSize()<<" bytes ";
	std::cout<<"\r";
	
}