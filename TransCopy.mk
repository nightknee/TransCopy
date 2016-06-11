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
Date                   :=11/06/16
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
LinkOptions            :=  
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
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/TransCopy.cpp$(ObjectSuffix) $(IntermediateDirectory)/TransCopyConfiguration.cpp$(ObjectSuffix) 



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


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


