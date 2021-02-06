#pragma once
#ifndef EXCEPTION_
#define EXCEPTION_
#include<exception>
#include<string>

class InpException :public std::exception {									//Виключення визначене як ієрархія класу

    std::string exception_message_;											//Строкова змінна для опису повідомлення

public:
    InpException(std::string exception_message) { exception_message_ = exception_message; }	//Конструктор класу

    virtual const char* what() { return exception_message_.c_str(); }					 //Метод what("Що сталось?") для опису помилки

};

#endif