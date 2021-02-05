#include "Person.h"

Person::Person()
{
    SurName = "Default";
    Name = "Default";
    Birthday = Date();
}

Person::Person(const Person& cpy)
{
    this->SurName = cpy.SurName;
    this->Name = cpy.Name;
    this->Birthday = cpy.Birthday;
}

Person::Person(std::string _Surname, std::string _Name, int _day, int _month, int _year)
{
    setSureName(_Surname);
    setName(_Name);
    setBirthday(_day, _month, _year);
}

Person::Person(std::string _Surname, std::string _Name, Date& Birthday_)
{
    setSureName(_Surname);
    setName(_Name);
    if (Birthday_.getYear() > 2002) {
	  std::cout << "Age limit is 18!" << std::endl;
	  std::cout << "You must be older that " << CURRENYEARVALUE - Birthday.getYear() << std::endl;
	  std::cout << "Birth year was set as 2000 " << std::endl;
	  Birthday_.setYear(2000);
    }
    Birthday = Birthday_;
}


std::string Person::getSureName() { return SurName; }

void Person::setSureName(std::string _SureName)
{
    this->SurName = _SureName;
    if (SurName.length() < 1 || SurName.length()> 10) {
	  std::cout<<"Surname is too short or too long" << std::endl;
	  std::cout << "Surname was set as Rowling " << std::endl;
	  SurName = "Rowling";
    }

    if (!HaveDigits(SurName)) {
	  std::cout << std::endl<<"Wrong input-----------------------" << std::endl;
	  std::cout << "Surname field cannot include numbers" << std::endl;
	  std::cout << "Surname was set as Rowling " << std::endl;
	  SurName = "Rowling";
    }
}


std::string Person::getName() { return Name; }

void Person::setName(std::string _Name)
{
    this->Name = _Name;
    if (Name == SurName) {
	  std::cout << "Name and Surname cannot be similar" << std::endl;
	  std::cout << "Name was set as Joanne " << std::endl;
	  Name = "Joane";
    }
    if (Name.length() < 1 || Name.length() > 10) {
	  std::cout << "Name is too short or too long" << std::endl;
	  std::cout << "Name was set as Joanne " << std::endl;
	  Name = "Joane";
    }

    if (!HaveDigits(Name)) {
	  std::cout << "Name field cannot include numbers" << std::endl;
	  std::cout << "Name was set as Joanne " << std::endl;
	  Name = "Joane";
    }
}

Date Person::getBirthday() { return Birthday; }

void Person::setBirthday(int _day, int _month, int _year)
{
    if (_year > 2002) {
	  std::cout << "Age limit is 18!" << std::endl;
	  std::cout << "You must be older that " << CURRENYEARVALUE - _year << std::endl;
	  _year = 2000;
    }
    Birthday = Date(_day, _month, _year);
}


bool Person::operator==(const Person& obj)
{
    return this->SurName == obj.SurName && this->Name == obj.Name && this->Birthday == obj.Birthday;
}
Person::operator std::string()
{
    return this->SurName + " " + this->Name + " " + std::to_string(Birthday.getDay()) + ":" + std::to_string(Birthday.getMonth()) +
	  ":" + std::to_string(Birthday.getYear());
}

void Person::writeObject(std::ostream& write)
{
    int str_size = SurName.size() + 1;
    int str_size1 = Name.size() + 1;
    write.write(reinterpret_cast<char*>(&str_size), sizeof(int));
    write.write(reinterpret_cast<char*>(&str_size1), sizeof(int));

    char* chrs = new char[str_size];
    char* chrs1 = new char[str_size1];

    strcpy(chrs, SurName.c_str());
    strcpy(chrs1, Name.c_str());

    write.write(reinterpret_cast<char*>(&chrs[0]), sizeof(char) * str_size);
    write.write(reinterpret_cast<char*>(&chrs1[0]), sizeof(char) * str_size1);
    write.write(reinterpret_cast<char*>(&Birthday), sizeof(Date));

    delete[]chrs;
    delete[]chrs1;
}

void Person::readObject(std::istream& read)
{
    int str_size = 0;

    read.read(reinterpret_cast<char*>(&str_size), sizeof(int));
    char* chrs = new char[str_size];
    read.read(reinterpret_cast<char*>(&chrs[0]), sizeof(char) * str_size);
    SurName = chrs;
    Name = chrs;

    read.read(reinterpret_cast<char*>(&Birthday), sizeof(Date));
    delete[]chrs;
}


bool Person::HaveDigits(std::string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
	  if (isdigit(str[i]))
	  {
		return false;
	  }
    }
    return true;
}