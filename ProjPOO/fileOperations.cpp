#include "fileOperations.hpp"

void FileOperations::createFile(QString Path , QString name){
        QString path = Path+"/"+name;
        qDebug() << path << "\n";
        FILE *f = fopen(path.toStdString().c_str(), "w");
        QFile file;
        file.open(f, QIODevice::WriteOnly);
        file.write("");
        file.close();
        fclose(f);
}

void FileOperations::removeFile(QString Path , QString name){
        QString path = Path+"/"+name;

        try
        {
            bool failed = (!QFile::exists(path) == true);
            if (failed)
                throw 10;
            else
                QFile::remove(path);
        }
        catch ( int e )
        {
            qDebug() << "Error: could not delete file ! (Error "<<e<<").\n";
        }
}

bool FileOperations::check(QString Path, QString name){
    QString path = Path+"/"+name;
    return QFile::exists(path);
}

void FileOperations::writeToFile(QString Path ,
                                QString name ,
                                QString textToFile){
    QString path = Path+"/"+name;
    QFile out;
    try
    {
        bool failed = !(QFile::exists(path) == true);
        if (failed)
            throw 11;
        else {
            FILE *f = fopen(path.toStdString().c_str(), "a");
            out.open(f, QIODevice::Append);
            out.write(textToFile.toStdString().c_str());
            out.close();
            fclose(f);
        }

    }
    catch ( int e )
    {
            qDebug() << "Error: could not delete file ! (Error "<<e<<").\n";
    }
}

