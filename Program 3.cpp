#include <iostream>
#include <string>
using namespace std;

int getUserInput(int minimum, int maximum)
{
	int choice;
	cin >> choice;
	return choice;
}

void mainMenu()
{
	cout << "1. Add class " << endl;
	cout << "2. Remove last class " << endl;
	cout << "3. Update class " << endl;
	cout << "4. View all class " << endl;
	cout << "5. Exit " << endl;
}

void addClass(string classTitles[10], int classStudentCount[10], int& classCount)
{
	classCount++;
	cout << "ADD CLASS" << endl;
	//string title;
	cout << "New class title : " ;
	cin.ignore();
	getline (cin, classTitles[10]);
	

	cout << "new student Count: " ;
	cin >> classStudentCount[10];
	
	cout << "Class added" << endl << endl;


	if (classCount == 10)
	{
		cout << "Class list already full" << endl;
	}
}

void removeLastClass(string classTitles[10], int classStudentCount[10], int& classCount)
{
	classCount--;
	
	if (classCount == 0)
	{
		cout << "Class list already empty" << endl;
	}
}
void updateClass(string classTitles[10], int classStudentCount[10], int& classCount)
{



}

void viewAllClass(string classTitles[10], int classStudentCount[10], int& classCount)
{

	for (int i = 0; i < classCount; i++)
	{
		cout << i + 1 << ".     " << classTitles[i] << ", " << "Students: " << classStudentCount[i] << endl;


	}

}

int main()
{
	string classTitles[10];
	int classStudentCount[10];
	int classCount = 0;
	bool done = false;

	while (!done)
	{
		mainMenu();
		int choice = getUserInput(1, 5);
		
		if ( choice == 1 )
		{
			addClass(classTitles, classStudentCount, classCount);
	
		}
		else if ( choice == 2)
		{
			removeLastClass(classTitles, classStudentCount, classCount);

		}

		else if (choice == 3)
		{
			updateClass(classTitles, classStudentCount, classCount);

		}

		else if (choice == 4)
		{
			viewAllClass(classTitles, classStudentCount, classCount);

		}

		else if (choice == 5)
		{
			done = true;
			
		}
		
	}
	
	return 0;
}
