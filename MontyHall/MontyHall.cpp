// MontyHall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const bool switchDoor = false;




	bool doors[3] = { false, false, true };
	unsigned long attempts = 0, cars = 0, donkeys = 0;

	srand(time(NULL));

	cout << "Number of attempts? ";
	cin >> attempts;

	std::cout.setstate(std::ios_base::failbit);

	for (unsigned long x = 0; x < attempts; x++)
	{
		doors[0] = doors[1] = doors[2] = false;
		int doorWithCar = (int)(rand() % 3);					// Pick random door
		int doorIndexPicked = 0;								// User picks door #1
		doors[doorWithCar] = true;								// Place car behind the door

		// Pick door #1, host reveals door #2 or #3
		if (doors[1] == true)
		{
			// Car behind door #2, open door #3
			cout << "Door 3 opened! It's a donkey! ";
			if (switchDoor)
			{
				cout << "Switching to door #2...";
				doorIndexPicked = 1;							// Switch to door #2	(Player will win)
			}
			else
				cout << "Staying on door #1...";				// Stay on door #1		(Player will lose)
		}
		else if (doors[2] == true)
		{
			cout << "Door 2 opened! It's a donkey! ";
			if (switchDoor)
			{
				cout << "Switching to door #3...";
				doorIndexPicked = 2;							// Switch to door #3	(Player will win)
			}
			else
				cout << "Staying on door #1...";				// Stay on door #1		(Player will lose)
		}
		else
		{
			int randomDoorOpened = (int)(rand() % 2 + 1);		// Car is behind door #1
			int switchToDoor = (randomDoorOpened == 1 ? 2 : 1);	// Open door #2 or door #3
			cout << "Door " << randomDoorOpened + 1 << " opened! It's a donkey! ";

			if (switchDoor)										// Switch to door not opened (Player will lose)
			{
				cout << "Switching to door #" << switchToDoor + 1 << "...";
				doorIndexPicked = switchToDoor;
			}
			else
																// Stay on door #1		(Player will win)
			{
				cout << "Staying on door #1...";
			}
		}


		if (doors[doorIndexPicked])
		{
			cout << "You got a car!" << endl;
			cars++;
		}
		else
		{
			cout << "You got a donkey!" << endl;
			donkeys++;
		}
	}
	std::cout.clear();

	cout << "Results for " << attempts << " attempts " << (switchDoor ? "switching" : "staying") << "! Cars: " << cars << ". Donkeys: " << donkeys << endl;
	system("pause");

	return 0;
}

