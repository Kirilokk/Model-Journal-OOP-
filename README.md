Real-life model Journal using OOP.

Task: Create a hierarchical class model that represents the model of real world objects.

Main class is Journal. Object of this class will be created. Secondaty classes: Date, Person, Author, Article, Exception, FileException.

While designing i used main OOP concepts: Encapsulation, inheritance,polymorphism,abstracion...

As for Relationships between classes and object: Depending on the situauion was choosing between Inheritance(Is-a), Argeration-Composition(has-a).

If exception happened all the error information saves to Excpetion/FileException and user will be noticed about kind of error and how to act.

The control file: main.cpp After executing program, user is able to choose betwen 8 menu item: 1.Input data(To create object) 2.Show table(Table of existing objects) 3.Write data to text file(data = object info) 4.Write data to binary file 5.Read data from file(and filling the table) 6.Search by text field(Search the object via text info) 7.Search by numeric field(Searcg the object via numeric info) 0.Exit program.

Class protorypes are in .h file and class body in .cpp file.

Programming language: C++.