#include "fileOperations.hpp"

void FileOperations::createFile(std::string Path , std::string name){
		std::string path = Path+"/"+name;
		std::cout << path<<"\n";
		std::ofstream outputFile(path);
		outputFile << "";
		outputFile.close();
	}
void FileOperations::removeFile(std::string Path , std::string name){
		std::string path = Path+"/"+name;
		 
		try
  		{
    		bool failed = (!std::ifstream(path) ==true);
    		if ( failed )
    			throw 10;
    		else
    			std::remove(path.c_str());
  		}
  		catch ( int e )
  		{
   			std::cout << "Error: could not delete file !\n";
 		}
	}
bool FileOperations::check(std::string Path, std::string name){
	std::string path = Path+"/"+name;
	std::ifstream infile(path);
    return infile.good();
}
void FileOperations::writeToFile(std::string Path , 
								std::string name , 
								std::string textToFile){
	std::string path = Path+"/"+name;
	std::ofstream out;
	try{
    	bool failed = (!std::ifstream(path) ==true);
    	if ( failed )
   			throw 11;
   		else{
   			out.open(path, std::ios::app);
			out << textToFile<<"\n";
			out.close();
		}
    			
    }
  		catch ( int e )
  		{
   			std::cout << "Error: file does not exists !\n";
 		}
}
	
