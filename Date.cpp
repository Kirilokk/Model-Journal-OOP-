#include "Date.h"

Date::Date()
{
    year = 2007;
    month = 10;
    day = 21;

}
Date::Date(const Date& cpy)
{
    year = cpy.year;
    month = cpy.month;
    day = cpy.day;
}

Date::Date(int _day, int _month, int _year)
{
    setYear(_year);
    setMonth(_month);
    setDay(_day);
}

int Date::getYear() { return year; }
int Date::getMonth() { return month; }
int Date::getDay() { return day; }


void Date::setYear(int _year)
{
    this->year = _year;
    if (year < 1940 || year >2020) {
	  std::cout << "Wrong year value" << std::endl;
	  std::cout << "Year was set as 2020" << std::endl;
	  year = 2020;
    }
}

void Date::setMonth(int _month)
{
    this->month = _month;
    if (month < 1 || month >12) {
	  std::cout << "Wrong month value" << std::endl;
	  std::cout << "Month was set as December(12)" << std::endl;
	  month = 12;
    }
}

void Date::setDay(int _day)
{
    this->day = _day;
    if (day >31) {

	  std::cout << "Wrong day value" << std::endl;
	  std::cout << "Day was set as 31" << std::endl;
	  day = 31;
    }
    else if (month == 2) {								//Перевірка чи місяць "лютий"
	  if (day > 29) {									//Якщо так, то днів має бути не більше 28
		std::cout << "Wrong day value" << std::endl;
		std::cout << "Day was set as 28(February)" << std::endl;
		day = 28;
	  }
	  else if (day == 29 && !bissextiledYear(year)) {			//Якщо більше 29, то перевірка чи рік високосний
		std::cout << "Wrong year value.It is not bissextile year" << std::endl;
		std::cout << "Day was set as 28(February)" << std::endl;
		day = 28;
	  }
    }
 }

Date::operator std::string()
{
    return std::to_string(this->day) + ":" + std::to_string(this->month) + ":" + std::to_string(this->year);
}

bool Date::operator==(const Date& d)
{
    return this->day == d.day && this->month == d.month && this->year == d.year;
}
std::ostream& operator<<(std::ostream& out, const Date& d)
{
    out << "<" << d.day << ":" << d.month << ":" << d.year << std::setw(2) << ">";
    return out;
}

void Date::writeObject(std::ostream& write)
{
    write.write(reinterpret_cast<char*>(&day), sizeof(int));
    write.write(reinterpret_cast<char*>(&month), sizeof(int));
    write.write(reinterpret_cast<char*>(&year), sizeof(int));
}

void Date::readObject(std::istream& read)
{
    read.read(reinterpret_cast<char*>(&day), sizeof(int));
    read.read(reinterpret_cast<char*>(&month), sizeof(int));
    read.read(reinterpret_cast<char*>(&year), sizeof(int));

}
	  
bool Date::bissextiledYear(int year)				      
{
    return year % 4 == 0;
}


