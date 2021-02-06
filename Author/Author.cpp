#include "Author.h"

Author::Author():Person()
{
   Position = ASSISTANT;
}

Author::Author(const Author& cpy) : Person(cpy)
{
    this->Position = cpy.Position;
}


Author::Author(std::string _SurName, std::string _Name, int _day, int _month, int _year, KindOfPosition _Position):
    Person(_SurName, _Name, _day, _month, _year)
{
    Position = _Position;
}

void Author::setKindOfPosition(KindOfPosition _Position)
{
    Position = _Position;
}

KindOfPosition Author::getKindOfPosition()					//Метод повертає цілочисельне значення enum
{
    return Position;
}

std::string Author::getStringKindOfPosition()					//Метод повертає строку при перетворенні цілочисельного 
												//значення enum за допомогою оператора switch
{
    switch (Position) {  
    case ASSISTANT:        return "Assistant"; break;
    case SENIOR_LECTURER:  return "Lecturer"; break;
    case DOCENT:		   return "Docent"; break;
    case PROFESSOR:	   return "Professor"; break;
    default:		   return "None"; break;
    }
}

void Author::writeObject(std::ostream& write)
{

    write.write(reinterpret_cast<char*>(&Position), sizeof(KindOfPosition));
}

void Author::readObject(std::istream& read)
{
    read.read(reinterpret_cast<char*>(&Position), sizeof(KindOfPosition));

}



