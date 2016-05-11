#include "Library.hpp"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int GetValidInput(int min, int max)
{
	int choice;
	cin >> choice;

	while (choice < min || choice > max)
	{
		cout << "Invalid choice. Try again: ";
		cin >> choice;
	}

	return choice;
}
int Adminmenu()
{
	cout << "1. Update book" << endl;
	cout << "2. Add book" << endl;
	cout << "3. Export database" << endl;
	int choice = GetValidInput(1, 3);
	
	return choice;
}
int PublicMenu()
{
	cout << "1. Search by title" << endl;
	cout << "2. Search by author" << endl;
	int choice = GetValidInput(1, 2);

	return choice;
}
int MainMenu()
{
	
	cout << "1. Public Access" << endl;
	cout << "2. Admin Access" << endl;
	cout << "3. Exit" << endl;
	int choice = GetValidInput(1, 3);
	cin >> choice;
	return choice;
}
void RunAdmin()
{
		Adminmenu();
		int choice2 = GetValidInput(1, 3);
		cin >> choice2;
		if (choice2 == 1)
		{
			cout << "UpdateBook()";
		}
		if (choice2 == 2)
		{
			cout << "AddBook()";
		}
		if (choice2 == 3)
		{
			cout << "SaveLibrary()";
		}

}
void RunPublic()
{
	PublicMenu();
	
	int choice1 = GetValidInput(1, 2);
	cin >> choice1;
	if (choice1 == 1)
	{
		cout << "SearchByTitle()";
	}
	if (choice1 == 2)
	{
		cout << "SearchByAuthor()";
	}
}
void Run()
{
	bool done = false;
	while (!done)
	{
		MainMenu();
		int choice = GetValidInput(1, 3);
		if (choice == 1)
		{
			RunPublic();
		}
		if (choice == 2)
		{
			RunAdmin();
		}
		if (choice == 3)
		{
			done = true;
		}
	}
}
int main()
{
	Library lib;
	lib.InitLibrary();

	Run();
	return 0;

}