#include <iostream>
#include <stdlib.h>
using namespace std;

void drawSeparator(int length)
{

	for (int i = 0; i< length; i++)
	{
		cout << "- ";
	}


}

void displayMenu(int round, int playerHP, int enemyHP)
{
	drawSeparator(30);
	cout << " " << endl << endl;
	round = round + 1;
	cout << "Round " << round << endl;
	cout << "Your HP: " << playerHP << "        ";
	cout << "Enemy HP: " << enemyHP << endl << endl;
	cout << "1.Attack" << endl;
	cout << "2.heal" << endl << endl;
	cout << "What do you do?" << endl;
	
}

int getChoice(int minimum, int maximum)
{
	int choice;
	cin >> choice;

	while (choice < minimum || choice > maximum)
		 {
		cout << "Invalid choice. Select an option between " << minimum << " and " << maximum << endl;
		cout << "What do you want to do: ";
		cin >> choice;
		cout << " " << endl;
		}
	
	return choice;
}

int getAttack()
{
	int attack = rand() % 10;
	return attack;
}

int getHealing()
{
	int healing = rand() % 7;
	return healing;
}


int main()
{
	
	int playerHP = 100;
	int enemyHP = 100;
	int round = 0;
	

	while (playerHP > 0 && enemyHP > 0)
	{
		
		displayMenu(round, playerHP, enemyHP);
		int choice = getChoice(1, 2);
		
		round++;

		if (choice == 1 )
		{
			enemyHP = enemyHP - getAttack();
			cout << "You attack your Enemy for " << getAttack() << " damage!" << endl;	
		}
		if (choice == 2 )
		{
			playerHP = playerHP + getHealing();
			cout << "You healed yourself for " << getHealing() << " points!" << endl;
		}
		
		
		int enemyChoice = rand() % 2;
		if (enemyChoice == 0)
		{
			playerHP = playerHP - getAttack();
			cout << "Enemy attacks you for " << getAttack() << " damage!" << endl;
		}
		if (enemyChoice == 1)
		{
			enemyHP = enemyHP + getHealing();
			cout << "Enemy heals themself for " << getHealing() << " points!" << endl;
		} 
			
		if (playerHP <= 0)
		{
			cout << " you lose" << endl;
			break;
		}
		if (enemyHP <= 0)
		{
			cout << "you win" << endl;
			break;
		}

	}




	return 0;
}