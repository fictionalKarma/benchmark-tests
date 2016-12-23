#ifndef FILE_OPERATIONS
#define FILE_OPERATIONS

#include <string>
#include <fstream>
#include <iostream>

class FileOperations{

public:
	FileOperations(){}
	/**
	creates a new file at a specified path 

	@param specifies the Path
	@param specifies the name of the new file

	@return no return yet
	*/
	void createFile(std::string Path , std::string name);
	/**
	removes a file at a specified Path

	@param specifies the Path
	@param specifies the name of the file

	@return no return yet sorry
	*/
	void removeFile(std::string Path , std::string name);
	/**
	checks whether a file exists at a specified path

	@param specifies the Path
	@param specifies the name of the file 

	@return returns false if file doesn't exist, true otherwise
	*/
	bool check(std::string Path , std::string name);
	/**

	writes a string at the end of a file 

	@param specifies the Path
	@param specifies the name of the file
	@param specifies the string to be appended to file

	@return no return yet sorry
	*/
	void writeToFile(std::string Path , std::string name , std::string textToFile);
};

#endif