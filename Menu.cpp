#include "Menu.h"
#include <iostream>
#include <iomanip>
#include "windows.h"
using std::cout;
using std::endl;
using std::cin;
using std::left;
using std::setw;



Menu::Menu()
{
}


Menu::~Menu()
{
}

int Menu::getChoice()
{
	return choice;
}

bool Menu::getMainMenuInput(Menu& x_menu)
{

	do
	{
		cout << left;
		cout << "\n\n\n\n\n";
		cout << setw(30) << "" << "Wright Brothers Airline Reservations System" << endl;
		cout << setw(30) << "" << "-------------------------------------------" << endl;
		cout << "\n";
		cout << setw(40) << "" << "1) Add passenger(s)" << endl;
		cout << setw(40) << "" << "2) Show seating" << endl;
		cout << setw(40) << "" << "3) Quit" << endl;
		cout << endl;
		cout << setw(30) << "" << "Please make a selection (1, 2 or 3): ";
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3)
		{
			system("cls");
			cout << "\n\n\n\n\n";
			cout << setw(40) << "" << "<Invalid Entry>" << endl;
			cout << setw(30) << "" << "Please enter a selection of 1, 2, or 3" << endl;
			Sleep(2000);
			system("cls");
		}

	} while (choice != 1 && choice != 2 && choice != 3);
	x_menu.choice = choice;
	return true;
}



