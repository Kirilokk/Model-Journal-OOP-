
#include <fstream>
#include <Windows.h>

using namespace std;
#define SIZE 8		    //Визначаємо константу для розміру масива

#include "Date.h";	    //Підключення усіх похідних модулів
#include "Person.h";
#include "Author.h";
#include "Article.h";
#include "Journal.h";
#include "Exception.h";
#include "FileException.h";


Journal* JournalInput(Article* ArtList, int countArticles, int _Pday, int _Pmonth, int Pyear);	//Функція ініцілізації основного об'єкту Журнал
Article* Input();														//Функція похідних об'єктів для класу Журнал
int Options();														//Елемент меню, вибір опції
void table(Journal& journal);												//Функія виведення таблиці
void Writing();														//Інтерактивний запис в консолі при записі в файл
bool FileIs_empty(std::ifstream& File);

void AddNum(Article*& arr, int& count);										//Функція при збільшенні розміру масиву(якщо обрали пункт 
																//"Введення даних",cтворення нового об'єту і запис в масив

template <class T>													//Визначення шаблону функцій для обрахунку середнього значення
T CalculateAverageNumPages(Journal* list, int length);
template <class T>
T CalculateAverageNumPrintedPages(Journal* list, int length);


int main() {

    Article A("Hopkins", "Tom", 10, 12, 2002, PROFESSOR, "Big start", 7, 7, 11, 12, 2020);	//Створення об'єктів класу для останього класу
    Article B("Polo", "Marko", 17, 12, 2000, ASSISTANT, "Headphones", 5, 4, 15, 12, 2020);
    Article C("Uchis", "Danil", 25, 10, 1998, DOCENT, "Vilagers", 10, 8, 22, 12, 2020);
    Article D("Hencks", "Tom", 30, 11, 2002, PROFESSOR, "Big start", 15, 15, 10, 10, 2019);
    Article E("Camera", "Chris", 25, 12, 1995, SENIOR_LECTURER, "Revolution", 6, 6, 15, 11, 2020);
    Article F("Masan", "Kirill", 16, 10, 1991, ASSISTANT, "World cup", 10, 9, 22, 10, 2020);
    Article G("Carrots", "Carl", 19, 11, 1990, DOCENT, "Physics", 9, 2, 13, 11, 2018);
    Article K("Freev", "Allan", 24, 12, 1997, PROFESSOR, "Speedy", 8, 6, 20, 12, 2020);
    Article L("Breevs", "Caren", 11, 10, 2000, ASSISTANT, "Archic", 14, 14, 19, 12, 2020);

    int size = SIZE;													//Так як далі потрібна буде саме ЗМІННА, створюємо її
    Article* ArticleArray = new Article[size];									//Створюємо масив типу Стаття і заповнення його значеннями
    ArticleArray[0] = A;
    ArticleArray[1] = B;
    ArticleArray[2] = C;
    ArticleArray[3] = D;
    ArticleArray[4] = E;
    ArticleArray[5] = F;
    ArticleArray[6] = G;
    ArticleArray[7] = K;

    Journal ReadList;													  //Читання з файлу буде відбуватись в цей об'єкт


    std::cout << "Menu" << std::endl;
    Journal* ListArray = new Journal(ArticleArray, SIZE, 17, 12, 2001);					 //Створення останнього об'єкту класа Журнал 

    //(*ListArray)[7] = L;											  	 //Застосування перевантаженого оператора індексування для вказівника на об'єкт
																//Спочатку розіменовую вказівник щоб отримати об'єкт, а потім застосов. оператор


    int Anum = 0;														 //Змінна для контролю розміру масиву
    int variant = Options();
    while (variant != 0)
    {
	  switch (variant)
	  {
	  case 1:														  //Введення даних для нового об'єкту
	  {
		int Pday = 0, Pmonth = 0, Pyear = 0;

		cout << "Enter publish day:";
		cin >> Pday;
		cout << "Enter publish month:";
		cin >> Pmonth;
		cout << "Enter publish year:";
		cin >> Pyear;


		cout << "Enter number of articles you want to create:";
		std::cin >> Anum;
		std::cout << std::endl;
		for (int i = 0; i < Anum; i++)
		{
		    cout << endl << "Article#" << size + 1 << endl;
		    AddNum(ArticleArray, size);									    //Перехід до функції яка додає новий об'єкт в масив
																    //і збільшує розмір динамічного масиву
		}

		ListArray = JournalInput(ArticleArray, size, Pday, Pmonth, Pyear);				    //Повторна ініцілізація основного об'єкту з переданими в нього
		break;													    //масиву,нового розміру і нової дати публікації
	  }
	  case 2: {
		std::string LDate = Date(31, 12, CURRENYEARVALUE);							      //Використання перевантаженого оператору приведення до типу
		std::cout << "Last day of this year: " << LDate << std::endl;						//Для виведення останнього дня цього року

		std::cout << "Total pages: " << ListArray->getTotalPages() << std::endl << endl;	      //Виведення загальної кількості сторінок усіх статей				
		std::cout << "Journal publish date: " << ListArray->getPublishDate() << std::endl << endl;	//Виведення дати публікації журналу(
																	  //Використання оператора потокового виведення
		cout << fixed;
		cout.precision(2);
		std::cout << "Average number of pages:" << CalculateAverageNumPages<float>(ListArray, size) << std::endl << endl;			    //Використання шаблонних функцій для обрахунку середньої кількості сторінок
		std::cout << "Average number of printed pages:" << CalculateAverageNumPrintedPages<float>(ListArray, size) << std::endl << endl;  //і друкованих аркущів
		std::cout << "Alphabet list of authors: | ";
		ListArray->AphabetAuthor();									    //Виведення алфавітного списку з імен авторів					  
		std::cout << " |" << std::endl << endl;
		table(*ListArray);											    //Виведення таблиці
		break;
	  }
	  case 3: {
		std::ofstream fileout;											    //Підключаємо файловий потік запису
		fileout.open("List.txt");										    //Файл куди буде відбуватись запис
		std::cout << "Writing data to text file.." << std::endl;
		if (!fileout.is_open()) {										    //Перевіряємо чи файл відкритий/інсує
		    throw FileException("Error opening file");
		    return 1;
		}
		Writing();

		fileout << "Total pages: " << ListArray->getTotalPages() << endl << "Journal publish date: " << ListArray->getPublishDate() << endl << "Average number of pages:"
		    << CalculateAverageNumPages<float>(ListArray, size) << endl << "Average number of printed pages:" << CalculateAverageNumPrintedPages<float>(ListArray, size) << std::endl;
		fileout << *ListArray;											    //Запис потрібної інформації в файл
																    //При записі в текстовий файл застосовувався перевантажений
																    //оператор виведення, який визначений в класі Journal і Date	
		fileout.close();												    //Закриваємо файл так як закінчили запис
		if (!fileout.good()) {										      //Перевірка чи читання відбулось успішно
		    throw FileException("Error reading file");
		    return 1;
		}
		break;
	  }
	  case 4:
	  {
		std::ofstream write("binary.dat", std::ios::out | std::ios::binary);			     //Підключаємо файловий потік запису
		std::cout << "Writing data to binary file.." << std::endl;					     //Файл куди буде відбуватись запис
		if (!write) {												    //Перевіряємо чи файл відкритий/інсує
		    throw FileException("Error opening file");
		    return 1;
		}
		Writing();													    //Інтерактивний запис в консолі
		ListArray->writeObject(write);									    //Запис об'єкту в бінарний файл.
		write.close();												    //Закриваємо файл так як закінчили запис								
		break;
	  }
	  case 5: {
		int var;
		std::cout << "Do you want to read from C:\...\ file.dat  file?" << std::endl;		    //Запит на читання з файлу
		std::cout << "1-Yes / 2 - No" << std::endl;
		std::cin >> var;
		switch (var)
		{
		case 1: {													    //Зчитування з запропонованого файлу
		    std::ifstream read("C:/Users/Kirilok/source/repos/CourseOOp/CourseOOp/file.dat", std::ios::out | std::ios::binary);
		    try
		    {
			  if (!read) {												    //Перевіряємо чи файл відкритий/інсує 
				throw FileException("Error opening file");
			  }
			  if (FileIs_empty(read))										     //Перевіряємо чи файл не пустий
			  {
				throw FileException("It is empty file");
			  }
			  ReadList.readObject(read);									     //Процес читання з файлу в об'єкт ListArray
			  *ListArray = ReadList;									     //Розіменування і використання перевантаженого оператора присвоєння
		    }
		    catch (FileException& e)											  //Якщо все ж пустий або неможливо відкрити то 
		    {															  //повератаємось назад в меню
			  std::cout << "Something went wrong..." << std::endl;
			  std::cout << e.what() << std::endl;
			  std::ifstream read("binary.dat", std::ios::out | std::ios::binary);
			  ReadList.readObject(read);									     //Процес читання з файлу в об'єкт ListArray
			  *ListArray = ReadList;									     //Розіменування і використання перевантаженого оператора присвоєння
			  std::cout << "Reading from default(binary.dat) file..." << std::endl;
			  break;
		    }

		    read.close();
		    if (!read.good()) {										      //Перевірка чи читання відбулось успішно
			  throw FileException("Error reading file");
			  return 1;
		    }
		    break;
		}
		case 2: {													    //Зчитування з  файлу за замовчуванням
		    std::ifstream read("binary.dat", std::ios::out | std::ios::binary);
		    std::cout << "Reading from default(binary.dat) file..." << std::endl;
		    if (!read) {												     //Перевіряємо чи файл відкритий/інсує 
			  std::cout << "Error opening file";
			  return 1;
		    }
		    ReadList.readObject(read);									     //Процес читання з файлу в об'єкт ListArray
		    *ListArray = ReadList;										      //Розіменування і використання перевантаженого оператора присвоєння
		    read.close();
		    if (!read.good()) {												 //Перевірка чи читання відбулось успішно
			  throw FileException("Error reading file");
			  return 1;
		    }
		    std::cout << "Reading from file successfully" << std::endl;
		    break;
		}
		default:														  //Якщо введено невірну опцію(не 1 і не 2)
		    std::cout << "Incorrect input...Try again" << std::endl;
		    break;
		}
		break;
	  }
	  case 6: {															  //Пошук за іменем
		std::string searchName;												  //Створюємо строкову змінну 
		std::cout << "Enter your search name" << std::endl;

		try
		{
		    std::cin.ignore();
		    std::cin >> searchName;											  //Введення слова за яким буде відбуватись пошук
		    if (searchName.length() <= 1) {										  //Виключна ситуація(При введені пустої строки
			  throw InpException("Empty string searchName was entered");
		    }
		}
		catch (InpException& e)
		{
		    std::cout << "Enter your search name again" << std::endl;
		    std::cin.ignore();												  //Повторне введення
		    std::cin >> searchName;
		}
		ListArray->SearchByName(searchName);									  //Функція пошуку за іменем
		break;
	  }
	  case 7: {															   //Пошук за числовим полем
		int SearchNum;
		std::cout << "Enter your search num of pages" << std::endl;
		try
		{
		    std::cin >> SearchNum;
		    if (SearchNum <= 0) {											  //Виключна ситуація(Шукане числове поле не може бути менше 0
			  throw InpException("Empty SearchNum was entered");
		    }
		}
		catch (InpException& e)
		{
		    system("cls");
		    std::cout << "Something went wrong..." << std::endl;
		    std::cout << e.what() << std::endl;
		    std::cout << "Enter your search num of pages again" << std::endl;
		    std::cin >> SearchNum;
		}

		ListArray->SearchByNumberPages(SearchNum);								  //Функція пошуку за числовим полем
		break;
	  }
	  }
	  variant = Options();													  //Повторний виклик для обрання опцій меню
    }

    delete[] ArticleArray;
    delete ListArray;
    return 0;
}

int Options() {//Меню програми
    int ind;
    std::cout << std::endl << "Choose option:" << std::endl;
    std::cout << "1. Input data\n" << "2. Show table\n" << "3. Write data to text file \n"
	  << "4. Write data to binary file \n" << "5. Read data from file\n" << "6. Search by text field\n" <<
	  "7. Search by numeric field\n" <<
	  "0. Exit program\n" << std::endl;
    std::cin >> ind;
    system("cls");
    return ind;
}

Article* Input() {										  //Функція ініцілізації об'єкту класу Article

    using namespace std;
    Article* ArticleArray = new Article();

    //Інцілізуємо потрібні змінні
    string Surname = "";
    string Name = "";
    string ArticleName = "";
    int Bday = 0, Bmonth = 0, Byear = 0;
    int Pday = 0, Pmonth = 0, Pyear = 0;
    KindOfPosition Position;
    int InpPosition;
    int NumPages = 0;
    float NumPrintedPages = 0;


    cout << "Enter surname: ";
    cin.ignore();
    getline(cin, Surname);

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, Name);


    cout << "Enter birth day: ";
    cin >> Bday;
    cout << "Enter birth month: ";
    cin >> Bmonth;
    cout << "Enter birth year: ";
    cin >> Byear;

    cout << "Enter kind of posiion(number[0:3]):";
    cin >> InpPosition;
    Position = static_cast<KindOfPosition>(InpPosition);				  //Передаємо цілочисельне значення в змінну типу enum

    std::cout << "Enter article name = ";
    cin.ignore();
    getline(cin, ArticleName);

    cout << "Enter number of pages: ";
    cin >> NumPages;
    cout << "Enter number of printed pages: ";
    cin >> NumPrintedPages;

    cout << "Enter present day: ";
    cin >> Pday;
    cout << "Enter present month: ";
    cin >> Pmonth;
    cout << "Enter present Byear: ";
    cin >> Pyear;


    try {												  //Обробка виключних ситуацій(Якщо ми пройдемо перевірку Try
													  //і ніяких помилок не виникне то в catch ми не зайдемо
	  ArticleArray->setSureName(Surname);
	  ArticleArray->setName(Name);
	  ArticleArray->setBirthday(Bday, Bmonth, Byear);
	  ArticleArray->setKindOfPosition(Position);
	  ArticleArray->setArticleName(ArticleName);
	  ArticleArray->setNumPages(NumPages);
	  ArticleArray->setNumPrintedPages(NumPrintedPages);
	  ArticleArray->setArtPresentDate(Pday, Pmonth, Pyear);
    }
    catch (InpException& e) {									  //Якщо щось не так і ми "Попадемось" то відбудеться виведення
													  //яка помилка виникла і значення полів будуть встановленні за замовчуванням
	  system("cls");
	  std::cout << "Something went wrong..." << std::endl;
	  std::cout << e.what() << std::endl;
	  std::cout << "All values was set as default..." << std::endl;

	  ArticleArray->setSureName("Kirill");
	  ArticleArray->setName("Topolyuk");
	  ArticleArray->setBirthday(17, 12, 2001);
	  ArticleArray->setKindOfPosition(ASSISTANT);
	  ArticleArray->setArticleName("Alien Space");
	  ArticleArray->setNumPages(7);
	  ArticleArray->setNumPrintedPages(7);
	  ArticleArray->setArtPresentDate(20, 12, 2020);

    }

    return ArticleArray;
}

Journal* JournalInput(Article* ArtList, int countArticles, int _Pday, int _Pmonth, int Pyear) {

    using namespace std;
    Journal* journal = new Journal();


    try {												  //Обробка виключних ситуацій(Якщо ми пройдемо перевірку Try
													  //і ніяких помилок не виникне то в catch ми не зайдемо
	  journal->setArticleList(ArtList, countArticles);
	  journal->setPublishDate(_Pday, _Pmonth, Pyear);
    }
    catch (InpException& e) {									   //Обробка виключних ситуацій(Якщо ми пройдемо перевірку Try
													  //і ніяких помилок не виникне то в catch ми не зайдемо
	  system("cls");
	  std::cout << e.what() << std::endl;
	  std::cout << "Something went wrong..." << std::endl;
	  std::cout << "All values was set as default..." << std::endl;

	  journal->setArticleList(ArtList, 1);
	  journal->setPublishDate(15, 15, 2020);

    }

    return journal;
}

void table(Journal& journal) {								  //Функція виведення таблиці

    //Основка логіка таблиці це використання маніпулятора setw(задає ширину поля) з потрібними параметрами

    std::cout << "------------------------------------------------------------"
	  << "---------------------------------------------\n";

    //Шапка таблиці

    std::cout << std::setw(3) << std::left << "|" << std::setw(9) << "Surname"
	  << std::setw(4) << "|" << std::setw(8) << "Name"
	  << std::setw(5) << "|" << std::setw(11) << "Birhday"
	  << std::setw(3) << "|" << std::setw(10) << "Position"
	  << std::setw(3) << "|" << std::setw(14) << "Article Name"
	  << std::setw(2) << "|" << std::setw(6) << "Pages"
	  << std::setw(2) << "|" << std::setw(8) << "Printed"
	  << std::setw(3) << "|" << std::setw(13) << "Present date"
	  << std::setw(1) << "|" << std::endl;
    std::cout << "------------------------------------------------------------"
	  << "---------------------------------------------\n";

    //Використання перевантаженого оператора потового виведення  ostream& operator<< який визначений в класі Журнал
    std::cout << journal;
    std::cout << "---------------------------------------------------------------"
	  << "------------------------------------------\n";
}

void Writing() {//Інтерактивний запис в консолі
    cout << " Writing....." << endl;
    for (int i = 1; i < 3; i++) {
	  cout << i * 50 << "%" << endl;
	  Sleep(i * 500);
    }
    cout << "Written in file successfully" << endl;
}

template <class T>
T CalculateAverageNumPages(Journal* list, int length)		//Шаблонна функція для обрахунку середної кільості сторінок статей
{

    T sum = 0;
    T _averagePages = 0;
    for (int i = 0; i < length; i++)
    {
	  sum += list->getArticleList()[i].getNumPages();				//Рахуємо кількість сторінок

    }
    _averagePages = sum / length;					//І ділимо на кількість статей
    return _averagePages;
}
template <class T>
T CalculateAverageNumPrintedPages(Journal* list, int length)//Шаблонна функція для обрахунку середної кільості друкованих аркушей статей(логіка така ж як і в попередній функції)
{

    T sum = 0;
    T _averagePages = 0;
    for (int i = 0; i < length; i++)
    {
	  sum += list->getArticleList()[i].getNumPrintedPages();

    }
    _averagePages = sum / length;
    return _averagePages;
}

void AddNum(Article*& arr, int& count) {			  //Функція яка додає новий об'єкт в клас(Приймає вказівник на посилання---тобто змінюючи масив в цьому полі
									  //ми змінюватимемо його в основній програмі( з count така ж історія)

    Article* newArr = new Article[count + 1];		  //Створюємо новий масив з розміром старого+1
    for (int i = 0; i < count; i++)
    {
	  newArr[i] = arr[i];					  //Записуємо старий масив в новий
    }
    newArr[count] = *Input();					  //Не заповнений останній елемент заповнюємо 

    count++;							  //Збільшення розміру
    delete[] arr;							  //Видалення старого вказівника на перший елемент
    arr = newArr;							  //Передаємо вказівник на перший елемент в масив.

}

bool FileIs_empty(std::ifstream& File)			//Перевірка чи пустий файл
{
    return File.peek() == std::ifstream::traits_type::eof();
}
