#define BOOST_TEST_MODULE transcopy

#include <boost/test/included/unit_test.hpp>
#include <boost/filesystem.hpp>

#include "../DiskObject.h"
#include "../DirectoryFactory.h"
#include "../Directory.h"
#include "../Exceptions/PathException.h"
#include "../FileFactory.h"
#include "../File.h"
#include "../Exceptions/FileException.h"
#include "../CmdOptionsDescription.h"
#include "../CmdOptionsParser.h"
#include "../Exceptions/CmdOptionsParserException.h"
#include "../TransCopyConfiguration.h"
#include "../FileParserContainer.h"
#include "../Exceptions/NotFoundParserException.h"
#include "../AbstractFileParse.h"
#include "../CopyHandler.h"
#include "../CopyStatus.h"
#include "../SizeFormatter.h"

//Diskobject
BOOST_AUTO_TEST_SUITE( TestDiskObject )

BOOST_AUTO_TEST_CASE( checkNotExistDirectoryDiskObject )
{
    boost::filesystem::path p("testDiskObject");        
    
    BOOST_CHECK_EQUAL(DiskObject::isExist("testDiskObject"), false);
}

BOOST_AUTO_TEST_CASE( checkExistDirectoryDiskObject )
{
    boost::filesystem::path p("testDiskObject");
    
    boost::filesystem::create_directory(p);
    
    BOOST_CHECK_EQUAL(DiskObject::isExist("testDiskObject"), true);
}

BOOST_AUTO_TEST_CASE( checkNotExistFileDiskObject )
{   
    BOOST_CHECK_EQUAL(DiskObject::isExist("testFileDiskObject.txt"), false);
}

BOOST_AUTO_TEST_CASE( checkExistFileDiskObject )
{   
    boost::filesystem::path p("testFileDiskObject.txt");   
    
    boost::filesystem::ofstream("testFileDiskObject.txt");
    
    BOOST_CHECK_EQUAL(DiskObject::isExist("testFileDiskObject.txt"), true);
}
BOOST_AUTO_TEST_SUITE_END()

//Directory:
BOOST_AUTO_TEST_SUITE( TestDirectory )

BOOST_AUTO_TEST_CASE( checkNotExistDirectory )
{
    boost::filesystem::path p("testDirectory");
    BOOST_CHECK_EQUAL(Directory::isExist("testDirectory"), false);
}

BOOST_AUTO_TEST_CASE( throwExceptionWhenCreateDirObjectWithNotExistDir )
{       
    BOOST_CHECK_THROW(DirectoryFactory::create("testDirectory"), PathException);
}

BOOST_AUTO_TEST_CASE( checkExistDirectory )
{
    boost::filesystem::path p("testDirectory");

    boost::filesystem::create_directory(p);
    
    BOOST_CHECK_EQUAL(Directory::isExist("testDirectory"), true);
}

BOOST_AUTO_TEST_CASE( createDirectoryObjectWithExistDir )
{     
    BOOST_CHECK(DirectoryFactory::create("testDirectory"));
}

BOOST_AUTO_TEST_SUITE_END()

//File:
BOOST_AUTO_TEST_SUITE( TestFile )

BOOST_AUTO_TEST_CASE( checkNotExistFile )
{
    boost::filesystem::path p("testFile.txt");
    BOOST_CHECK_EQUAL(File::isExist("testFile.txt"), false);
}

BOOST_AUTO_TEST_CASE( throwExceptionWhenCreateFileObjectWithNotExistFile )
{       
    BOOST_CHECK_THROW(FileFactory::create("testFile.txt"), FileException);
}

BOOST_AUTO_TEST_CASE( checkExistFile )
{
    boost::filesystem::path p("testFile.txt");
    
    boost::filesystem::ofstream("testFile.txt") << "Test content to check file size";        
    
    BOOST_CHECK_EQUAL(File::isExist("testFile.txt"), true);
}

BOOST_AUTO_TEST_CASE( createFileObjectWithExistFile )
{     
    BOOST_CHECK(FileFactory::create("testFile.txt"));
}   

BOOST_AUTO_TEST_CASE( testFileSize )
{     
    filePtr file = FileFactory::create("testFile.txt");   
    
    BOOST_CHECK(file->size() == 31);
} 

BOOST_AUTO_TEST_CASE( testFileExtension )
{     
    filePtr file = FileFactory::create("testFile.txt");
    
    BOOST_CHECK(file->extension() == ".txt");
} 

BOOST_AUTO_TEST_CASE( testFileName )
{     
    filePtr file = FileFactory::create("testFile.txt");
    
    BOOST_CHECK(file->getFileName() == "testFile");
} 

BOOST_AUTO_TEST_SUITE_END()

////Cmd options parser     
BOOST_AUTO_TEST_SUITE( testCmdOptionsParser)
BOOST_AUTO_TEST_CASE(OptionsRequired)
{
    char* argv[] = {
        "testfile",
        "-f",
        "testfile"
    };           
    
    int argc = 3;
    
    cmdOptionsDescriptionPtr desc {new CmdOptionsDescription("test1")};
    
    desc->add_options()
            ("file-path,f", boost::program_options::value<std::string>()->required(), "Path to list files")
            ("destination-path,d", boost::program_options::value<std::string>()->required(), "Path when copy files");      
    
    BOOST_CHECK_THROW(CmdOptionsParser::parseCmdOptionsToConfiguration(argc, argv, desc), CmdOptionsParserException);
}    

BOOST_AUTO_TEST_CASE(TestTransCopyConfigurationOptionString)
{
    BOOST_CHECK_EQUAL(TransCopyConfiguration::getInstance()->getStringOptionValue("file-path"), "testfile");
} 

BOOST_AUTO_TEST_SUITE_END()

//File parser contaier        
BOOST_AUTO_TEST_SUITE( testFileParserContainer)
BOOST_AUTO_TEST_CASE(findTxtParser)
{    
    BOOST_CHECK_THROW(FileParserContainer::getInstance().findParser(".txt"), NotFoundParserException);
}

BOOST_AUTO_TEST_CASE(findPlsParser)
{    
    BOOST_CHECK(FileParserContainer::getInstance().findParser(".pls"));
}

BOOST_AUTO_TEST_SUITE_END()        
        
//Pls parser
BOOST_AUTO_TEST_SUITE(testPlsParser)
BOOST_AUTO_TEST_CASE(plsParserParsingFileExtension)
{
    AbstractFileParse *parser = FileParserContainer::getInstance().findParser(".pls");
    
    BOOST_CHECK_EQUAL(parser->parsingFileExtension(), ".pls");
}  

BOOST_AUTO_TEST_CASE(parsedFilesIsEmpty)
{
    boost::filesystem::ofstream("plstest.pls") << "[playlist]" << std::endl << "NumberOfEntries=1" << std::endl << "File1=testFile.txt";
    
    AbstractFileParse *parser = FileParserContainer::getInstance().findParser(".pls");
    
    filePtr file = FileFactory::create("plstest.pls");
    
    const ParsedFiles *parsed = parser->parse(file);
    
    BOOST_CHECK_EQUAL(parsed->isEmpty(), false);
}  

BOOST_AUTO_TEST_CASE(sizeOfParsedFiles)
{    
    AbstractFileParse *parser = FileParserContainer::getInstance().findParser(".pls");
    
    filePtr file = FileFactory::create("plstest.pls");
    
    const ParsedFiles *parsed = parser->parse(file);
    
    BOOST_CHECK(parsed->size() == 31);
}  

BOOST_AUTO_TEST_CASE(numberOfParsedFiles)
{
    AbstractFileParse *parser = FileParserContainer::getInstance().findParser(".pls");
    
    filePtr file = FileFactory::create("plstest.pls");
    
    const ParsedFiles *parsed = parser->parse(file);
    
    ParsedFilesStorage *storageParsedFiles = parsed->getParsedFilesStorage();
    
    BOOST_CHECK(storageParsedFiles->size() == 1);
} 
BOOST_AUTO_TEST_SUITE_END()
        
//Copy handler
BOOST_AUTO_TEST_SUITE( testCopyHandler)
BOOST_AUTO_TEST_CASE(copyFiles)
{
    CopyHandler handler = {"plstest.pls", "testDirectory/"};           
    
    handler.copy();
    
    filePtr file = FileFactory::create("testDirectory/testFile.txt");
    
    BOOST_CHECK(file->size() == 31);
}        

BOOST_AUTO_TEST_CASE( wrongFilePath )
{
    BOOST_CHECK_THROW(new CopyHandler("plstest.plsss", "testDirectory/"), FileException);
} 

BOOST_AUTO_TEST_CASE( wrongDirectoryPath )
{
    BOOST_CHECK_THROW(new CopyHandler("plstest.pls", "teeestDirectory/"), PathException);
} 
BOOST_AUTO_TEST_SUITE_END() 
        
//Exceptions
BOOST_AUTO_TEST_SUITE(testExceptionsMsg)
BOOST_AUTO_TEST_CASE(testBaseException)
{
    try {
        throw BaseException("Test throw");
    } catch(BaseException e) {
        BOOST_CHECK_EQUAL(e.what(), "Test throw");
    }
}    

BOOST_AUTO_TEST_CASE(testPathException)
{
    try {
        directoryPtr dir = DirectoryFactory::create("testDirectory/testDirectory");
    } catch(PathException e) {
        BOOST_CHECK_EQUAL(e.what(), "testDirectory/testDirectory path doesn't exist");
    }
}    

BOOST_AUTO_TEST_CASE(testFileException)
{
    try {
        filePtr dir = FileFactory::create("testingfile.txt");
    } catch(FileException e) {
        BOOST_CHECK_EQUAL(e.what(), "testingfile.txt file doesn't exist");
    }
} 

BOOST_AUTO_TEST_CASE(testNotFoundParserException)
{
    try {
        FileParserContainer::getInstance().findParser(".txt");
    } catch(NotFoundParserException e) {
        BOOST_CHECK_EQUAL(e.what(), "Not found parser for .txt extension");
    }
}    
BOOST_AUTO_TEST_SUITE_END()  

BOOST_AUTO_TEST_SUITE(testSizeFormatter)  
BOOST_AUTO_TEST_CASE(testFormattedBytesToKilo)
{
    SizeFormatter formatter(FormatTo::KILOBYTES);
    
    BOOST_CHECK(formatter.formatBytes(1000) == "1KB");
}    
BOOST_AUTO_TEST_CASE(testShortestBytestToGigabytesFormatted)
{
    SizeFormatter formatter(FormatTo::SHORTEST);
    
    BOOST_CHECK(formatter.formatBytes(1891775158) == "1.89GB");
}   

BOOST_AUTO_TEST_CASE(testShortestBytestToBytesFormatted)
{
    SizeFormatter formatter(FormatTo::SHORTEST);
    
    BOOST_CHECK(formatter.formatBytes(850) == "850B");
} 

BOOST_AUTO_TEST_CASE(testShortestBytestToMegaBytesFormatted)
{
    SizeFormatter formatter(FormatTo::SHORTEST);
    
    BOOST_CHECK(formatter.formatBytes(354420000) == "354MB");
}

BOOST_AUTO_TEST_CASE(testShortestBytestToKiloBytesFormatted)
{
    SizeFormatter formatter(FormatTo::SHORTEST);
    
    BOOST_CHECK(formatter.formatBytes(459002) == "459KB");
}
BOOST_AUTO_TEST_SUITE_END()        