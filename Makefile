CC = g++
CCFLAGS = -g -O3 -O2 -std=c++14 -Wall -Bstatic -lboost_program_options -lboost_system -lboost_filesystem -lboost_regex
LDFLAGS =
LDLIBS = -L/usr/lib/libboost_program_options.a -L/usr/lib/libboost_system.a -L/usr/lib/libboost_filesystem.a -L/usr/lib/libboost_regex.a

all: TransCopy.o TransCopyConfiguration.o PlsParser.o
	$(CC) $(LDLIBS) TransCopyConfiguration.o -o TransCopy

TransCopyConfiguration.o:  TransCopyConfiguration.cpp TransCopyConfiguration.h Configuration.h
	$(CC)  -c TransCopyConfiguration.cpp  $(CCFLAGS)
	
PlsParser.o: PlsParser.cpp PlsParser.h AbstractFileParse.h
	$(CC) -c PlsParser.cpp -o PlsParser.o $(CCFLAGS)

TransCopy.o:  TransCopy.cpp TransCopy.h TransCopyConfiguration.h FileParserContainer.h AbstractFileParse.h MainExceptionHandler.h Exceptions/BaseException.h FileManager.h CopyStatus.h CmdOptionsParser.h CmdOptionsDescription.h CmdOptionsParsed.h
	$(CC) -c TransCopy.cpp -o TransCopy.o $(CCFLAGS)

clean: 
	rm *.o