#include "TransCopy.h"

TransCopy::TransCopy()
{
	this->cmdDesc = std::make_shared<CmdOptionsDescription>("Options");	
	this->cmdDesc->setOptionToDisplay("help");
	
	this->messageRun();

}

TransCopy::~TransCopy(){}

int TransCopy::run(int argc,char** argv){	
	try{
		this->setSettingsFromArgs(argc,argv);
		
		if(TransCopyConfiguration::getConfiguration().withGui()){
			
		}else{
			this->cmdCopy();
		}
	}
	catch(const BaseException *e){
		MainExceptionHandler::handleException(e);
	}
	catch(std::exception *e){
		MainExceptionHandler::handleException(e);
	}
	return 0;
}

void TransCopy::setSettingsFromArgs(int argc,char** argv){
	try{	
		CmdOptionsParsed* parsedOptions = this->parseCmdArgs(argc,argv);
		
		Configuration* tempConfiguration =  this->setConfigurationFromCmd(parsedOptions);
		
		TransCopyConfiguration::getConfiguration().setConfiguration(tempConfiguration);
	}	
	catch (const CmdOptionsParserException *e){	
		if (this->cmdDesc->displayDiscription()){
			
			std::cout<<this->cmdDesc->sourceCmdDescription()<<std::endl;
			
			throw new BaseException;			
		}
		throw e;
	}
}

void TransCopy::cmdCopy(){
	this->createFileToParseObject();
		
	this->createPathDestinationObject();
		
	this->setParser();

	if(this->manageParseFile()){
		this->copyParsedFiles();
	}
}

CmdOptionsParsed* TransCopy::parseCmdArgs(int argc,char** argv){			
		return CmdOptionsParser::parseAndGetCmdOptionsValue(argc,argv,this->cmdDesc);
}

Configuration* TransCopy::setConfigurationFromCmd(CmdOptionsParsed* parsedOptions){
	Configuration* tempConfiguration = new Configuration;
	
	if(parsedOptions->optionExist("file-path")){
		tempConfiguration->fileToParsePath = parsedOptions->optionStringValue("file-path");
	}
		
	if(parsedOptions->optionExist("destination-path")){
		tempConfiguration->destinationPath = parsedOptions->optionStringValue("destination-path");
	}
	if(parsedOptions->optionExist("notyficate")){
		tempConfiguration->notyficate = true;
	}
	if(parsedOptions->optionExist("terminal")){
		tempConfiguration->gui = false;
	}
	return tempConfiguration;
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
}


void TransCopy::helpMessage(){
	
}

void TransCopy::setFileToParse(std::shared_ptr<File> f){
	this->fileToParse = f;
}

std::shared_ptr<File> TransCopy::getFileToParse(){
	return this->fileToParse;
}

void TransCopy::createFileToParseObject(){
	File* file = FileManager::createFileObject(TransCopyConfiguration::getConfiguration().getFileToParsePath());
	this->fileToParse = std::make_shared<File>(*file);
}

void TransCopy::createPathDestinationObject(){
	fs::path* path = FileManager::createPathObject(TransCopyConfiguration::getConfiguration().getDestinationPath());
	this->pathDestination = std::make_shared<fs::path>(*path);
}

void TransCopy::setParser(){
	this->parser = FileParserContainer::getInstance().findParser(this->fileToParse->getExntenstion());
}

bool TransCopy::manageParseFile(){
	return this->parser->parse(this->fileToParse);
}

void TransCopy::copyParsedFiles(){
	FileVector *files = this->parser->getParsedSongs();
	
	this->setCopyStatusValues(files);
	
	for(FileVector::iterator i = files->begin() ; i != files->end() ; ++i){			
		if(FileManager::copyFile(*i,TransCopyConfiguration::getConfiguration().getDestinationPath())){
			CopyStatus::getCopyStatus().increaseCopiedNumberFiles();
			CopyStatus::getCopyStatus().addCopiedFileSize( i->size());
			
			if(TransCopyConfiguration::getConfiguration().notyficate()){
				this->showCopyStats();
			}
		}
	}
	std::cout<<std::endl;
}

void TransCopy::setCopyStatusValues(FileVector *files){
	CopyStatus::getCopyStatus().setAllFilesSize( this->parser->getAllFilesSize());
	CopyStatus::getCopyStatus().setNumberOfAllFiles(files->size());
}

void TransCopy::showCopyStats(){
	std::cout<<"\r";
	std::cout<<"Copied: "<<CopyStatus::getCopyStatus().getCopiedNumberFiles()<<" of  "<<CopyStatus::getCopyStatus().getNumberOfAllFiles()<<" files ";
	std::cout<<" Copied: "<<CopyStatus::getCopyStatus().getCopiedFilesSize()<<" of  "<<CopyStatus::getCopyStatus().getAllFilesSize()<<" bytes ";
	std::cout<<"\r";
	
}