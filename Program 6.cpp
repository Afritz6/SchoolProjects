#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Color
{

	string color;
	int r, g, b;
};
struct Type
{

	string name;
};
struct Clothing
{

	string name;
	Color* ptrColor;
	Type* ptrType;
};
struct Outfit
{

	string name;
	Clothing* ptrHead;
	Clothing* ptrTop;
	Clothing* ptrBottom;

	void outfit()
	{
		ptrHead = NULL;
		ptrTop = NULL;
		ptrBottom = NULL;
	}
};

int main()
{
	Type allTypes[3];
	allTypes[0].name = "head";
	allTypes[1].name = "top";
	allTypes[2].name = "bottom";

	Color allColors[8];
	allColors[0].color = "red";
	allColors[0].r = 255;
	allColors[0].g = 0;
	allColors[0].b = 0;

	allColors[1].color = "green";
	allColors[1].r = 0;
	allColors[1].g = 255;
	allColors[1].b = 0;

	allColors[2].color = "blue";
	allColors[2].r = 0;
	allColors[2].g = 0;
	allColors[2].b = 255;

	allColors[3].color = "yellow";
	allColors[3].r = 255;
	allColors[3].g = 255;
	allColors[3].b = 0;

	allColors[4].color = "magenta";
	allColors[4].r = 255;
	allColors[4].g = 0;
	allColors[4].b = 255;

	allColors[5].color = "cyan";
	allColors[5].r = 0;
	allColors[5].g = 255;
	allColors[5].b = 255;

	allColors[6].color = "white";
	allColors[6].r = 255;
	allColors[6].g = 255;
	allColors[6].b = 255;

	allColors[7].color = "black";
	allColors[7].r = 0;
	allColors[7].g = 0;
	allColors[7].b = 0;

	Clothing allClothes[9];
	allClothes[0].name = "Baseball cap";
	allClothes[0].ptrColor = &allColors[0];
	allClothes[0].ptrType = &allTypes[0];

	allClothes[1].name = "Top hat";
	allClothes[1].ptrColor = &allColors[1];
	allClothes[1].ptrType = &allTypes[0];

	allClothes[2].name = "Scarf";
	allClothes[2].ptrColor = &allColors[2];
	allClothes[2].ptrType = &allTypes[0];

	allClothes[3].name = "T-shirt";
	allClothes[3].ptrColor = &allColors[3];
	allClothes[3].ptrType = &allTypes[1];

	allClothes[4].name = "Blouse";
	allClothes[4].ptrColor = &allColors[4];
	allClothes[4].ptrType = &allTypes[1];

	allClothes[5].name = "Button-up Shirt";
	allClothes[5].ptrColor = &allColors[5];
	allClothes[5].ptrType = &allTypes[1];

	allClothes[6].name = "Jeans";
	allClothes[6].ptrColor = &allColors[6];
	allClothes[6].ptrType = &allTypes[2];

	allClothes[7].name = "Skirt";
	allClothes[7].ptrColor = &allColors[7];
	allClothes[7].ptrType = &allTypes[2];

	allClothes[8].name = "Cargo Shorts";
	allClothes[8].ptrColor = &allColors[0];
	allClothes[8].ptrType = &allTypes[2];

	bool start = false;
	while (!start)
	{
		Outfit outfit;
		bool done = false;

		while (!done)
		{
			for (int i = 0; i < 9; i++)
			{
				cout << i << ".\t" << allClothes[i].ptrColor->color << "\t" << allClothes[i].ptrType->name << "\t" << allClothes[i].name << endl;
			}
			cout << "Enter 0-8 for selection or anything else to finish Make selection: ";
			int choice;
			cin >> choice;
			if (choice >= 0 && choice < 9)
			{
				if (allClothes[choice].ptrType->name == "head")
				{
					outfit.ptrHead = &allClothes[choice];
				}
				else if (allClothes[choice].ptrType->name == "top")
				{
					outfit.ptrTop = &allClothes[choice];
				}
				else
				{
					outfit.ptrBottom = &allClothes[choice];
				}
			}
			else
			{
				done = true;
			}
		}
		cout << "Please enter a name for this outfit: ";
		cin >> outfit.name;

		ofstream output(outfit.name + ".txt");
		output << outfit.name << endl;
		if (outfit.ptrBottom == NULL)
		{
			output << "Bottom: Nude\n";
		}
		else
		{
			output << outfit.ptrBottom->name << "\t" << outfit.ptrBottom->ptrColor->color << "\t" << outfit.ptrBottom->ptrColor->r << "\t" << outfit.ptrBottom->ptrColor->g << "\t" << outfit.ptrBottom->ptrColor->b << endl;
		}

		if (outfit.ptrTop == NULL)
		{
			output << "Top: Nude\n";
		}

		else
		{
			
			output << outfit.ptrTop->name << "\t" << outfit.ptrTop->ptrColor->color << "\t" << outfit.ptrTop->ptrColor->r << "\t" << outfit.ptrTop->ptrColor->g << "\t" << outfit.ptrTop->ptrColor->b << endl;
		}

		if (outfit.ptrHead == NULL)
		{
			output << "Head: Nude\n";
		}

		else
		{
			output << outfit.ptrHead->name << "\t" << outfit.ptrHead->ptrColor->color << "\t" << outfit.ptrHead->ptrColor->r << "\t" << outfit.ptrHead->ptrColor->g << "\t" << outfit.ptrHead->ptrColor->b << endl;
		}

		output.close();

		done = false;
		while (!done)
		{
			cout << "Would you like to create another outfit? (y or n)";
			char again;
			cin >> again;
			if (again == 'y')
			{
				start = false;
				done = true;
			}
			else if (again == 'n')
			{
				start = true;
				done = true;
			}
		}
	}

	
	return 0;
}