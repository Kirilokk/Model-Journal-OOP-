#include "Article.h"

Article::Article():Author()
{
    ArticleName = "Earth history";
    NumPages = 10;
    NumPrintedPages = 10;
    ArtPresentDate = Date();
}

Article::Article(const Article& cpy):Author(cpy)
{
    ArticleName = cpy.ArticleName;
    NumPages = cpy.NumPages;
    NumPrintedPages = cpy.NumPrintedPages;
    ArtPresentDate = cpy.ArtPresentDate;
   
}

Article::Article(std::string _SurName, std::string _Name, int B_day, int B_month, int B_year, KindOfPosition _Position, 
    std::string _ArticleName, int _NumPages, float _NumPrintedPages, int Pr_day, int Pr_month, int Pr_year)
    :Author(_SurName, _Name, B_day, B_month, B_year, _Position)
{
    setArticleName(_ArticleName);
    setNumPages(_NumPages);
    setNumPrintedPages(_NumPrintedPages);
    ArtPresentDate = Date(Pr_day, Pr_month, Pr_year);
}

Article::Article(std::string _SurName, std::string _Name, int B_day, int B_month, int B_year, KindOfPosition _Position,
    std::string _ArticleName, int _NumPages, float _NumPrintedPages, Date& _ArtPresentDate)
    :Author(_SurName, _Name, B_day, B_month, B_year, _Position)
{
    setArticleName(_ArticleName);
    setNumPages(_NumPages);
    setNumPrintedPages(_NumPrintedPages);
    ArtPresentDate = _ArtPresentDate;

}

std::string Article::getArticleName(){ return ArticleName;}

void Article::setArticleName(std::string _ArticleName)//Dont check isdigit because Artname can have digits в звіті написати
{
    ArticleName = _ArticleName;
    if (ArticleName.length() < 1 || ArticleName.length() > 10) {
	  std::cout << "ArticleName is too short or too long" << std::endl;
	  std::cout << "Earth history" << std::endl;
	  ArticleName = "Earth history";
    }
}

int Article::getNumPages() { return NumPages; }

void Article::setNumPages(int _NumPages)
{
    NumPages = _NumPages;
    if (NumPages < MinNumPages|| NumPages > MaxNumPages) {
	  std::cout << "Number of  pages must not be less than " << MinNumPages<<" pages" << std::endl;
	  std::cout << "And must not be more than " << MaxNumPages << " pages" << std::endl;
	  NumPages = MinNumPages;
    }
}
float Article::getNumPrintedPages(){ return NumPrintedPages;}

void Article::setNumPrintedPages(float _NumPrintedPages)
{
    NumPrintedPages = _NumPrintedPages;

    if (NumPrintedPages > NumPages) {
	  std::cout << "Number of Printed pages cannot be more than number of pages" << std::endl;
	  std::cout << "Number of Printed pages  was set as " << NumPages << std::endl;
	  NumPrintedPages = NumPages;
    }
}
Date Article::getArtPresentDate(){ return ArtPresentDate;}

void Article::setArtPresentDate(int Pr_day, int Pr_month, int Pr_year)
{
    ArtPresentDate = Date(Pr_day,Pr_month,Pr_year);
}


void Article::writeObject(std::ostream& write)
{
    int str_size = ArticleName.size() + 1;
    write.write(reinterpret_cast<char*>(&str_size), sizeof(int));
    char* chrs = new char[str_size];
    strcpy(chrs, ArticleName.c_str());
    write.write(reinterpret_cast<char*>(&chrs[0]), sizeof(char) * str_size);
    
    int str_size1 = SurName.size() + 1;
    write.write(reinterpret_cast<char*>(&str_size1), sizeof(int));
    char* chrs1 = new char[str_size1];
    strcpy(chrs1, SurName.c_str());
    write.write(reinterpret_cast<char*>(&chrs1[0]), sizeof(char) * str_size1);

    int str_size2 = Name.size() + 1;
    write.write(reinterpret_cast<char*>(&str_size2), sizeof(int));
    char* chrs2 = new char[str_size2];
    strcpy(chrs2, Name.c_str());
    write.write(reinterpret_cast<char*>(&chrs2[0]), sizeof(char) * str_size2);


    write.write(reinterpret_cast<char*>(&Birthday), sizeof(Date));
    write.write(reinterpret_cast<char*>(&Position), sizeof(KindOfPosition));
    write.write(reinterpret_cast<char*>(&NumPages), sizeof(int));
    write.write(reinterpret_cast<char*>(&NumPrintedPages), sizeof(float));
    write.write(reinterpret_cast<char*>(&ArtPresentDate), sizeof(Date));

    delete[]chrs;
    delete[]chrs1;
    delete[]chrs2;
}


void Article::readObject(std::istream& read)
{

    int str_size = 0;
    int str_size1 = 0;
    int str_size2 = 0;
    read.read(reinterpret_cast<char*>(&str_size), sizeof(int));
    char* chrs = new char[str_size];
    read.read(reinterpret_cast<char*>(&chrs[0]), sizeof(char) * str_size);
    ArticleName = chrs;

    read.read(reinterpret_cast<char*>(&str_size1), sizeof(int));
    chrs = new char[str_size1];
    read.read(reinterpret_cast<char*>(&chrs[0]), sizeof(char) * str_size1);
    SurName = chrs;

    read.read(reinterpret_cast<char*>(&str_size2), sizeof(int));
    chrs = new char[str_size2];
    read.read(reinterpret_cast<char*>(&chrs[0]), sizeof(char) * str_size2);
    Name = chrs;

    read.read(reinterpret_cast<char*>(&Birthday), sizeof(Date));
    read.read(reinterpret_cast<char*>(&Position), sizeof(KindOfPosition));

    read.read(reinterpret_cast<char*>(&NumPages), sizeof(int));
    read.read(reinterpret_cast<char*>(&NumPrintedPages), sizeof(float));
    read.read(reinterpret_cast<char*>(&ArtPresentDate), sizeof(Date));

    delete[]chrs;
}

