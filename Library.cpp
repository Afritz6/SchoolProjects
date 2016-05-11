#include "Library.hpp"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void Library::InitLibrary()
{
	ifstream input("library.txt");
	string buffer;

	input >> buffer;
	input >> buffer;
	input >> buffer;

	int id;
	string title;
	string first, middle, last;

	bookCount = 0;

	while (input >> id >> title >> first >> middle >> last)
	{
		booklist[bookCount].title = title;
		booklist[bookCount].id = id;
		booklist[bookCount].author = first + " " + middle + " " + last;
		bookCount++;

	}
	input.close();

}
