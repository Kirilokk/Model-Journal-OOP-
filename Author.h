#pragma once
#ifndef AUTHOR_H
#define AUTHOR_H

#include "Person.h"


enum KindOfPosition {				  //Оголошую перерахування Посада
    ASSISTANT,
    SENIOR_LECTURER,
    DOCENT,
    PROFESSOR
};

class Author : public Person			  //Наслдування класу Person
{
protected:
    KindOfPosition Position;

public:
    Author();																	  //Конструктор за замовчуванням
    Author(const Author& cpy);														  //Конструктор копіювання
    Author(std::string _SurName, std::string _Name, int _day, int _month, int _year, KindOfPosition _Position);	  //Конструктор ініцілізації

    //Аксесори
    KindOfPosition getKindOfPosition();					  //Геттери
    std::string getStringKindOfPosition();				  //Геттер для того щоб отримати строкову змінну при передачі цілочисельного значення enum

    void setKindOfPosition(KindOfPosition _Position);			  //Сеттер

    void writeObject(std::ostream& write);				  //Функція запису в бінарний файл
    void readObject(std::istream& read);					  //Функція читання з бінарного файлу
   

};



#endif

