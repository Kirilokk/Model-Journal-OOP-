#pragma once
#ifndef DATE_H
#define DATE_H
#define MINYEARVALUE 1950
#define CURRENYEARVALUE 2020


#include <iostream>
#include <string>
#include <iomanip>

class Date
{
private:						   //Інкапсуляція(закритість елементів класу)
    int year;
    int month;
    int day;


public:
    Date();						  //Конструктор за замовчуванням
    Date(const Date& cpy);			  //Конструктор копіювання
    Date(int _day, int _month, int _year);  //Конструктор ініцілізації
    
     //Аксесори
    int getYear();//Гетери
    int getMonth();
    int getDay();

    void setYear(int year);//Сетери
    void setMonth(int month);
    void setDay(int day);

    friend std::ostream& operator<< (std::ostream& out, const Date& d);	//Оператор потокового виведення дати у вигляді <day:month:year>
    operator std::string();								//Оператор приведення до типу строки(Щоб отимати дату строковою змінною)
    bool operator==(const Date& d);							//Оператор порівняння дати

    void writeObject(std::ostream& write);					//Функція запису в бінарний файл
    void readObject(std::istream& read);						//Функція читання з бінарного файлу
    
    bool bissextiledYear(int year);							//Функція визначення високосного року

};


#endif
