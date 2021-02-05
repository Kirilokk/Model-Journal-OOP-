#include "Journal.h"


Journal::Journal()
{
    countArticles = 0;
    ArticleList = new Article[countArticles];
    PublishDate = Date();
    TotalPages = 0;
}

Journal::Journal(Article* _ArticleList, int _countArticles, Date& _PublishDate)
{
   
    if (ArticleList) {
	  delete[]ArticleList;
    }
    countArticles = _countArticles;
    ArticleList = new Article[countArticles];


    for (int i = 0; i < countArticles; i++)
    {
	  ArticleList[i] = _ArticleList[i];
    }

    for (int i = 0; i < countArticles; i++)
    {
	  TotalPages += ArticleList[i].getNumPages();
    }
    PublishDate = _PublishDate;

}

Journal::Journal(Article* _ArticleList, int _countArticles, int P_day, int P_month, int P_year)
{
    if (ArticleList) {
	  delete[]ArticleList;
    }
    countArticles = _countArticles;
    ArticleList = new Article[countArticles];


    for (int i = 0; i < countArticles; i++)
    {
	  ArticleList[i] = _ArticleList[i];
    }

    for (int i = 0; i < countArticles; i++)
    {
	  TotalPages += ArticleList[i].getNumPages();
    }
    PublishDate = Date(P_day,P_month, P_year); 
}

Journal::Journal(const Journal& cpy)
{
    if (ArticleList) {
	  delete[]ArticleList;
    }
    countArticles = cpy.countArticles;
    ArticleList = new Article[cpy.countArticles];


    for (int i = 0; i < cpy.countArticles; i++)
    {
	  ArticleList[i] = cpy.ArticleList[i];
    }

    for (int i = 0; i < cpy.countArticles; i++)
    {
	  TotalPages += ArticleList[i].getNumPages();
    }
    PublishDate = cpy.PublishDate;
}

Journal::~Journal()
{
    if (ArticleList) {
	  delete[]ArticleList;
    }
}

Date Journal::getPublishDate(){ return PublishDate;}

Article* Journal::getArticleList(){ return ArticleList;}

void Journal::setPublishDate(int _Pday, int _Pmonth, int _Pyear)
{
    PublishDate = Date(_Pday, _Pmonth, _Pyear);
}
float Journal::getTotalPages(){  return TotalPages;}

void Journal::setArticleList(Article* _List, int _count)
{
    if (ArticleList) {
	  delete[]ArticleList;
    }
    countArticles = _count;
    ArticleList = new Article[countArticles];


    for (int i = 0; i < countArticles; i++)
    {
	  ArticleList[i] = _List[i];
    }
    for (int i = 0; i < countArticles; i++)
    {
	  TotalPages += ArticleList[i].getNumPages();
    }
}

void Journal::AphabetAuthor()
{
    std::string Info;
    for (int i = 0; i < countArticles; i++)
    {
	  Info += ArticleList[i].getName() +" ";
    }
    std::istringstream ist(Info);
    using input_str = std::istream_iterator<std::string>;
    for (const auto& info : std::multiset<std::string>(input_str(ist), input_str()))
	  std::cout << info << " ";
}


Article& Journal::operator[](int index)
{ 
	  return ArticleList[index];
}

Journal& Journal::operator=(const Journal& other)
{
    countArticles = other.countArticles;
    PublishDate = other.PublishDate;
    if (ArticleList) {
	  delete[]ArticleList;
    }
    countArticles = other.countArticles;
    ArticleList = new Article[other.countArticles];


    for (int i = 0; i < countArticles; i++)
    ArticleList[i] = other.ArticleList[i];
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Journal& journal)//Перевантажений оператор потокового виводу
{
    for (int i = 0; i < journal.countArticles; i++)
    {
	  out << std::setw(3) << "|" << std::setw(9) << journal.ArticleList[i].getSureName() << std::setw(4) << "|" << std::setw(8) << journal.ArticleList[i].getName()
		<< std::setw(1) << "|" << std::setw(2) << "" << journal.ArticleList[i].getBirthday() << std::setw(3) << "|" << std::setw(10) << journal.ArticleList[i].getStringKindOfPosition()
		<< std::setw(3) << "|" << std::setw(14) << journal.ArticleList[i].getArticleName() << std::setw(3) << "|" << std::setw(5) << journal.ArticleList[i].getNumPages()
		<< std::setw(4) << "|" << std::setw(6) << journal.ArticleList[i].getNumPrintedPages() << std::setw(1) << "|" << std::setw(2) << "" << journal.ArticleList[i].getArtPresentDate()
		<< std::setw(1) << "|" << std::endl;
    }
    return out;
}

void Journal::SearchByName(std::string compStr)
{
    bool check = false;
    for (int i = 0; i <countArticles; i++)
    {
	  if (compStr == ArticleList[i].getSureName() || compStr == ArticleList[i].getName() || compStr == ArticleList[i].getArticleName()){
		std::cout << "File with name " << compStr << " was found in Article #" << i+1 << std::endl;
		check = true;
	  }
    }
    if (!check) {
    std::cout << "File with name " << compStr << " was not found "<< std::endl;
    }
}

void Journal::SearchByNumberPages(int SearchNum)
{
    bool check = false;
    for (int i = 0; i < countArticles; i++)
    {
	  if (SearchNum == ArticleList[i].getNumPages() || SearchNum == ArticleList[i].getNumPrintedPages()) {
		std::cout << "File with pages " << SearchNum << " was found in Article #" << i+1 << std::endl;
		check = true;
	  }
    }
    if (!check) {
    std::cout << "File with pages " << SearchNum << " was not found " << std::endl;
    }
}

void Journal::writeObject(std::ostream& write)
{
    write.write(reinterpret_cast<char*>(&countArticles), sizeof(int));
    for (int i = 0; i < countArticles; i++) {
	  ArticleList[i].writeObject(write);
    }
    write.write(reinterpret_cast<char*>(&TotalPages), sizeof(int));
    write.write(reinterpret_cast<char*>(&PublishDate), sizeof(Date));

}

void Journal::readObject(std::istream& read)
{
    read.read(reinterpret_cast<char*>(&countArticles), sizeof(int));
    if (ArticleList) {
	  delete[]ArticleList;
    }
    ArticleList = new Article[countArticles];
    for (int i = 0; i < countArticles; i++) {
	  ArticleList[i].readObject(read);
    }
    read.read(reinterpret_cast<char*>(&TotalPages), sizeof(int));
    read.read(reinterpret_cast<char*>(&PublishDate), sizeof(Date));

}
