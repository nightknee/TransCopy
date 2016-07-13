##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TransCopy
ConfigurationName      :=Debug
WorkspacePath          :=/home/karwan/C++/TransCopy
ProjectPath            :=/home/karwan/C++/TransCopy/TransCopy
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=karwan
Date                   :=13/07/16
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
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="TransCopy.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lboost_program_options -lboost_system -lboost_filesystem -pthread
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
CXXFLAGS :=  -g -O0 -Wall -std=c++14 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/TransCopy.cpp$(ObjectSuffix) $(IntermediateDirectory)/TransCopyConfiguration.cpp$(ObjectSuffix) $(IntermediateDirectory)/Song.cpp$(ObjectSuffix) $(IntermediateDirectory)/Songs.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlsParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainExceptionHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/File.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileParserContainer.cpp$(ObjectSuffix) \
	



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

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

$(IntermediateDirectory)/Song.cpp$(ObjectSuffix): Song.cpp $(IntermediateDirectory)/Song.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/Song.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Song.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Song.cpp$(DependSuffix): Song.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Song.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Song.cpp$(DependSuffix) -MM "Song.cpp"

$(IntermediateDirectory)/Song.cpp$(PreprocessSuffix): Song.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Song.cpp$(PreprocessSuffix) "Song.cpp"

$(IntermediateDirectory)/Songs.cpp$(ObjectSuffix): Songs.cpp $(IntermediateDirectory)/Songs.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/karwan/C++/TransCopy/TransCopy/Songs.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Songs.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Songs.cpp$(DependSuffix): Songs.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Songs.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Songs.cpp$(DependSuffix) -MM "Songs.cpp"

$(IntermediateDirectory)/Songs.cpp$(PreprocessSuffix): Songs.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Songs.cpp$(PreprocessSuffix) "Songs.cpp"

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


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


