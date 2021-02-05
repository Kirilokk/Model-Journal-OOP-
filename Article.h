#pragma once
#ifndef ARTICLE_H
#define ARTICLE_H

#define MinNumPages 5			//Визначення потрібних констант
#define MaxNumPages 20


#include "Author.h"

class Article : public Author		//Наслідування класу Author
{
private:
    std::string ArticleName;
    int NumPages;
    float NumPrintedPages;
    Date ArtPresentDate;

public:
    Article();																	   //Конструктор за замовчуванням
    Article(const Article& cpy);														   //Конструктор копіювання

    Article(std::string _SurName, std::string _Name, int B_day, int B_month, int B_year, KindOfPosition _Position,   //Конструктор ініцілізація№1
	  std::string ArticleName, int NumPages, float NumPrintedPages, int Pr_day, int Pr_month, int Pr_year);

    Article(std::string _SurName, std::string _Name, int B_day, int B_month, int B_year, KindOfPosition _Position,  //Конструктор ініцілізація№1
	  std::string ArticleName, int NumPages, float NumPrintedPages, Date& _ArtPresentDate);


    //Аксесори
    std::string getArticleName();						  //Геттери
    int getNumPages();
    float getNumPrintedPages();
    Date getArtPresentDate();

    void setArticleName(std::string _ArticleName);			  //Сеттери
    void setNumPages(int _NumPages);
    void setNumPrintedPages(float _NumPrintedPages);
    void setArtPresentDate(int Pr_day, int Pr_month, int Pr_year);


    void writeObject(std::ostream& write);				  //Функція запису в бінарний файл
    void readObject(std::istream& read);					  //Функція читання з бінарного файлу
};




#endif
