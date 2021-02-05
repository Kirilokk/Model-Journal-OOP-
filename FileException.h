#pragma once
#ifndef FILEEXCEPTION_
#define FILEEXCEPTION_
#include<exception>
#include<string>

class FileException :public std::exception {									//Виключення визначене як ієрархія класу 
															     //Виникає при помилках з файлами
    std::string file_exception_message_;											//Строкова змінна для опису повідомлення

public:
    FileException(std::string exception_message) { file_exception_message_ = exception_message; }	//Конструктор класу

    virtual const char* what() { return file_exception_message_.c_str(); }					 //Метод what("Що сталось?") для опису помилки

};

#endif
 