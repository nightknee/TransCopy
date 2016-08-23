##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release_static
ProjectName            :=TransCopy
ConfigurationName      :=Release_static
WorkspacePath          :=/home/karwan/C++/TransCopy
ProjectPath            :=/home/karwan/C++/TransCopy/TransCopy
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=karwan
Date                   :=23/08/16
CodeLitePath           :=/home/karwan/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="TransCopy.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  /usr/lib/libboost_program_options.a /usr/lib/libboost_system.a /usr/lib/libboost_filesystem.a /usr/lib/libboost_regex.a
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O3 -O2 -std=c++14 -Wall -Wl,-Bstatic -lboost_program_options -lboost_system -lboost_filesystem -lboost_regex $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/TransCopy.cpp$(ObjectSuffix) $(IntermediateDirectory)/TransCopyConfiguration.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlsParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainExceptionHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/File.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileParserContainer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Exceptions_BaseException.cpp$(ObjectSuffix) $(IntermediateDirectory)/Exceptions_FileNotExistException.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Exceptions_NotFoundParserException.cpp$(ObjectSuffix) $(IntermediateDirectory)/Exceptions_PathNotExistException.cpp$(ObjectSuffix) $(IntermediateDirectory)/Exceptions_OpenFileException.cpp$(ObjectSuffix) $(IntermediateDirectory)/CopyStatus.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/TransCopy.cpp$(ObjectSuffix): TransCopy.cpp $(IntermediateDirectory)/TransCopy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/TransCopy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TransCopy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TransCopy.cpp$(DependSuffix): TransCopy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TransCopy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TransCopy.cpp$(DependSuffix) -MM "TransCopy.cpp"

$(IntermediateDirectory)/TransCopy.cpp$(PreprocessSuffix): TransCopy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TransCopy.cpp$(PreprocessSuffix) "TransCopy.cpp"

$(IntermediateDirectory)/TransCopyConfiguration.cpp$(ObjectSuffix): TransCopyConfiguration.cpp $(IntermediateDirectory)/TransCopyConfiguration.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/TransCopyConfiguration.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TransCopyConfiguration.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TransCopyConfiguration.cpp$(DependSuffix): TransCopyConfiguration.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TransCopyConfiguration.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TransCopyConfiguration.cpp$(DependSuffix) -MM "TransCopyConfiguration.cpp"

$(IntermediateDirectory)/TransCopyConfiguration.cpp$(PreprocessSuffix): TransCopyConfiguration.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TransCopyConfiguration.cpp$(PreprocessSuffix) "TransCopyConfiguration.cpp"

$(IntermediateDirectory)/PlsParser.cpp$(ObjectSuffix): PlsParser.cpp $(IntermediateDirectory)/PlsParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/PlsParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlsParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlsParser.cpp$(DependSuffix): PlsParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlsParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlsParser.cpp$(DependSuffix) -MM "PlsParser.cpp"

$(IntermediateDirectory)/PlsParser.cpp$(PreprocessSuffix): PlsParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlsParser.cpp$(PreprocessSuffix) "PlsParser.cpp"

$(IntermediateDirectory)/MainExceptionHandler.cpp$(ObjectSuffix): MainExceptionHandler.cpp $(IntermediateDirectory)/MainExceptionHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/MainExceptionHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainExceptionHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainExceptionHandler.cpp$(DependSuffix): MainExceptionHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainExceptionHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainExceptionHandler.cpp$(DependSuffix) -MM "MainExceptionHandler.cpp"

$(IntermediateDirectory)/MainExceptionHandler.cpp$(PreprocessSuffix): MainExceptionHandler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainExceptionHandler.cpp$(PreprocessSuffix) "MainExceptionHandler.cpp"

$(IntermediateDirectory)/File.cpp$(ObjectSuffix): File.cpp $(IntermediateDirectory)/File.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/File.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/File.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/File.cpp$(DependSuffix): File.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/File.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/File.cpp$(DependSuffix) -MM "File.cpp"

$(IntermediateDirectory)/File.cpp$(PreprocessSuffix): File.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/File.cpp$(PreprocessSuffix) "File.cpp"

$(IntermediateDirectory)/FileManager.cpp$(ObjectSuffix): FileManager.cpp $(IntermediateDirectory)/FileManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/FileManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileManager.cpp$(DependSuffix): FileManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FileManager.cpp$(DependSuffix) -MM "FileManager.cpp"

$(IntermediateDirectory)/FileManager.cpp$(PreprocessSuffix): FileManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileManager.cpp$(PreprocessSuffix) "FileManager.cpp"

$(IntermediateDirectory)/FileParserContainer.cpp$(ObjectSuffix): FileParserContainer.cpp $(IntermediateDirectory)/FileParserContainer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/FileParserContainer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileParserContainer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileParserContainer.cpp$(DependSuffix): FileParserContainer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileParserContainer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FileParserContainer.cpp$(DependSuffix) -MM "FileParserContainer.cpp"

$(IntermediateDirectory)/FileParserContainer.cpp$(PreprocessSuffix): FileParserContainer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileParserContainer.cpp$(PreprocessSuffix) "FileParserContainer.cpp"

$(IntermediateDirectory)/Exceptions_BaseException.cpp$(ObjectSuffix): Exceptions/BaseException.cpp $(IntermediateDirectory)/Exceptions_BaseException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/Exceptions/BaseException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exceptions_BaseException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exceptions_BaseException.cpp$(DependSuffix): Exceptions/BaseException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exceptions_BaseException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Exceptions_BaseException.cpp$(DependSuffix) -MM "Exceptions/BaseException.cpp"

$(IntermediateDirectory)/Exceptions_BaseException.cpp$(PreprocessSuffix): Exceptions/BaseException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exceptions_BaseException.cpp$(PreprocessSuffix) "Exceptions/BaseException.cpp"

$(IntermediateDirectory)/Exceptions_FileNotExistException.cpp$(ObjectSuffix): Exceptions/FileNotExistException.cpp $(IntermediateDirectory)/Exceptions_FileNotExistException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/Exceptions/FileNotExistException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exceptions_FileNotExistException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exceptions_FileNotExistException.cpp$(DependSuffix): Exceptions/FileNotExistException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exceptions_FileNotExistException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Exceptions_FileNotExistException.cpp$(DependSuffix) -MM "Exceptions/FileNotExistException.cpp"

$(IntermediateDirectory)/Exceptions_FileNotExistException.cpp$(PreprocessSuffix): Exceptions/FileNotExistException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exceptions_FileNotExistException.cpp$(PreprocessSuffix) "Exceptions/FileNotExistException.cpp"

$(IntermediateDirectory)/Exceptions_NotFoundParserException.cpp$(ObjectSuffix): Exceptions/NotFoundParserException.cpp $(IntermediateDirectory)/Exceptions_NotFoundParserException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/Exceptions/NotFoundParserException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exceptions_NotFoundParserException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exceptions_NotFoundParserException.cpp$(DependSuffix): Exceptions/NotFoundParserException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exceptions_NotFoundParserException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Exceptions_NotFoundParserException.cpp$(DependSuffix) -MM "Exceptions/NotFoundParserException.cpp"

$(IntermediateDirectory)/Exceptions_NotFoundParserException.cpp$(PreprocessSuffix): Exceptions/NotFoundParserException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exceptions_NotFoundParserException.cpp$(PreprocessSuffix) "Exceptions/NotFoundParserException.cpp"

$(IntermediateDirectory)/Exceptions_PathNotExistException.cpp$(ObjectSuffix): Exceptions/PathNotExistException.cpp $(IntermediateDirectory)/Exceptions_PathNotExistException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/Exceptions/PathNotExistException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exceptions_PathNotExistException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exceptions_PathNotExistException.cpp$(DependSuffix): Exceptions/PathNotExistException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exceptions_PathNotExistException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Exceptions_PathNotExistException.cpp$(DependSuffix) -MM "Exceptions/PathNotExistException.cpp"

$(IntermediateDirectory)/Exceptions_PathNotExistException.cpp$(PreprocessSuffix): Exceptions/PathNotExistException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exceptions_PathNotExistException.cpp$(PreprocessSuffix) "Exceptions/PathNotExistException.cpp"

$(IntermediateDirectory)/Exceptions_OpenFileException.cpp$(ObjectSuffix): Exceptions/OpenFileException.cpp $(IntermediateDirectory)/Exceptions_OpenFileException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/Exceptions/OpenFileException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exceptions_OpenFileException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exceptions_OpenFileException.cpp$(DependSuffix): Exceptions/OpenFileException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exceptions_OpenFileException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Exceptions_OpenFileException.cpp$(DependSuffix) -MM "Exceptions/OpenFileException.cpp"

$(IntermediateDirectory)/Exceptions_OpenFileException.cpp$(PreprocessSuffix): Exceptions/OpenFileException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exceptions_OpenFileException.cpp$(PreprocessSuffix) "Exceptions/OpenFileException.cpp"

$(IntermediateDirectory)/CopyStatus.cpp$(ObjectSuffix): CopyStatus.cpp $(IntermediateDirectory)/CopyStatus.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/CopyStatus.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CopyStatus.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CopyStatus.cpp$(DependSuffix): CopyStatus.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CopyStatus.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CopyStatus.cpp$(DependSuffix) -MM "CopyStatus.cpp"

$(IntermediateDirectory)/CopyStatus.cpp$(PreprocessSuffix): CopyStatus.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CopyStatus.cpp$(PreprocessSuffix) "CopyStatus.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


