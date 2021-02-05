#pragma once
#ifndef JOURNAL_H
#define JOURNAL_H

#include "Article.h";
#include <set>
#include <sstream>
#include <iterator>

class Journal
{
private:
    int countArticles;									//Змінна для розміру масива Стаття
    Article* ArticleList = new Article[countArticles];
    Date PublishDate;
    float TotalPages;

public:
    Journal();														//Конструктор за замовчуванням
    Journal(const Journal& cpy);											//Конструктор копіювання   
    Journal(Article* _ArticleList, int _countArticles,Date& _PublishDate);				//Конструктор ініцілізація№1
    Journal(Article* _ArticleList, int _countArticles, int P_day, int P_month, int P_year);	//Конструктор ініцілізація№2
    ~Journal();						    								//Деструктор для вивільнення пам'яті виділеної для масиву

    //Аксесори
    float getTotalPages();										//Геттери
    Date getPublishDate();
    Article* getArticleList();

    void setPublishDate(int _Pday, int _Pmonth, int _Pyear);				//Сеттери
    void setArticleList(Article* _List, int _count);

    void AphabetAuthor();										//Метод виведення алфавітного покажчика авторів


    Article& operator[](int index);									//Оператор індексування
    friend std::ostream& operator<< (std::ostream& out, const Journal& journal);	//Оператор потокового виведення
    Journal& operator=(const Journal& other);							//Оператор присвоювання

    void writeObject(std::ostream& write);							 //Функція запису в бінарний файл
    void readObject(std::istream& read);								 //Функція читання з бінарного файлу
    void SearchByName(std::string compStr);							 //Функція пошуку об'єкта класу за іменем
    void SearchByNumberPages(int SearchNum);							 //Функція пошуку об'єкта класу за числовим полем
};





#endif
