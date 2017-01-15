#ifndef FILE_OPERATIONS
#define FILE_OPERATIONS

#include <QString>
#include <QDebug>
#include <QFile>

class FileOperations{

public:
	/**
	creates a new file at a specified path 

	@param specifies the Path
	@param specifies the name of the new file

	@return no return yet
	*/
    static void createFile(QString Path , QString name);
	/**
	removes a file at a specified Path

	@param specifies the Path
	@param specifies the name of the file

	@return no return yet sorry
	*/
    static void removeFile(QString Path , QString name);
	/**
	checks whether a file exists at a specified path

	@param specifies the Path
	@param specifies the name of the file 

	@return returns false if file doesn't exist, true otherwise
	*/
    static bool check(QString Path, QString name);
	/**

	writes a string at the end of a file 

	@param specifies the Path
	@param specifies the name of the file
	@param specifies the string to be appended to file

	@return no return yet sorry
	*/
    static void writeToFile(QString Path , QString name , QString textToFile);
};

#endif
