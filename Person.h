#pragma once
#ifndef PERSON_H
#define PERSON_H


#include "Date.h"

class Person{

protected:													    
    std::string SurName;
    std::string Name;
    Date Birthday;											    //Агрегація

public:
    Person();												    //Конструктор за замовчуванням
    Person(const Person& cpy);						  			    //Конструктор копіювання
    Person(std::string _Surname, std::string _Name,int _day, int _month, int _year);    //Конструктор ініцілізації#1
    Person(std::string _Surname, std::string _Name, Date& Birthday_);			    //Конструктор ініцілізації#2

    //Аксесори
    std::string getSureName();//Гетери
    std::string getName();
    Date getBirthday();


    void setBirthday(int _day, int _month, int _year);//Сетери
    void setSureName(std::string _SureName);
    void setName(std::string _Name);

    operator std::string();					 //Оператор приведення до строкового типу(Щоб отримати інформацію з Person строковою змінною
    bool operator==(const Person& obj);			 //Оператор, що порівнює ім'я, прізвище, день народження і визначає чи це одна і та сама людина

    void writeObject(std::ostream& write);		  //Функція запису в бінарний файл
    void readObject(std::istream& read);			  //Функція читання з бінарного файлу
	  
private:
    bool HaveDigits(std::string& str);			  //Функція перевірки чи є в строкі цифри
};

#endif