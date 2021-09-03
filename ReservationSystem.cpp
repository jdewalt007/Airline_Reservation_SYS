#include "ReservationSystem.h"

#include "windows.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
using std::left;
using std::endl;



ReservationSystem::ReservationSystem()
{
	run();
}


ReservationSystem::~ReservationSystem()
{
}


void ReservationSystem::addPassenger()
{
	int flight_class = 0;
	cout << left;
	do
	{
		system("cls");
		cout << "\n\n\n";
		cout << setw(45) << "" << "Travel Details" << endl;
		cout << setw(45) << "" << "--------------" << endl;
		cout << "\n";
		cout << setw(45) << "" << "1) First Class" << endl;
		cout << setw(45) << "" << "2) Economy Class" << endl;
		cout << endl;
		cout << setw(45) << "" << "Enter 1 or 2: ";
		cin >> flight_class;
		if (flight_class != 1 && flight_class != 2)
		{
			system("cls");
			cout << "\n\n\n\n\n";
			cout << setw(40) << "" << "<Invalid Entry>" << endl;
			cout << setw(30) << "" << "Please enter a selection of 1 or 2" << endl;
			Sleep(2000);
			system("cls");
		}
	} while (flight_class != 1 && flight_class != 2);

	int num_passengers = 0;
	switch (flight_class)
	{
	case 1:
		do
		{
			cout << "\n";
			cout << setw(45) << "" << "Seats available " << firstClass.seatsLeft() << endl;
			cout << setw(45) << "" << "Number of passengers traveling together ";
			cout << "(1 or 2): ";
			cin >> num_passengers;
			if (num_passengers != 1 && num_passengers != 2)
			{
				system("cls");
				cout << "\n\n\n\n\n";
				cout << setw(40) << "" << "<Invalid Entry>" << endl;
				cout << setw(30) << "" << "Please enter a selection of 1 or 2" << endl;
				Sleep(2000);
				system("cls");
				cout << "\n\n\n";
				cout << setw(60) << "" << "Travel Details" << endl;
				cout << setw(60) << "" << "--------------" << endl;
			}
		} while (num_passengers != 1 && num_passengers != 2);
		break;
	case 2:
		do
		{
			cout << "\n";
			cout << setw(45) << "" << "Seats available " << economyClass.seatsLeft() << endl;
			cout << setw(45) << "" << "Number of passengers traveling together ";
			cout << "(1, 2 or 3): ";
			cin >> num_passengers;
			if (num_passengers != 1 && num_passengers != 2 && num_passengers != 3)
			{
				system("cls");
				cout << "\n\n\n\n\n";
				cout << setw(40) << "" << "<Invalid Entry>" << endl;
				cout << setw(30) << "" << "Please enter a selection of 1, 2 or 3" << endl;
				Sleep(2000);
				system("cls");
				cout << "\n\n\n";
				cout << setw(60) << "" << "Travel Details" << endl;
				cout << setw(60) << "" << "--------------" << endl;
			}
		} while (num_passengers != 1 && num_passengers != 2 && num_passengers != 3);
		break;
	}
	int seat_type;
	switch (flight_class)
	{
	case 1:
		do
		{
			cout << "\n\n";
			system("cls");
			cout << "\n";
			cout << setw(45) << "" << "Seating preference" << endl;
			cout << setw(45) << "" << "------------------" << endl << endl;
			cout << setw(45) << "" << "1) Aisle" << endl;
			cout << setw(45) << "" << "2) Window" << endl << endl;
			cout << setw(45) << "" << "Enter 1 or 2: ";
			cin >> seat_type;
			if (seat_type != 1 && seat_type != 2)
			{
				system("cls");
				cout << "\n\n\n\n\n";
				cout << setw(40) << "" << "<Invalid Entry>" << endl;
				cout << setw(30) << "" << "Please enter a selection of 1 or 2" << endl;

				Sleep(2000);
				system("cls");
				cout << "\n\n\n";
			}
		} while (seat_type != 1 && seat_type != 2);
		break;
	case 2:
		do
		{
			cout << "\n\n";
			system("cls");
			cout << setw(45) << "" << "Seating preference" << endl;
			cout << setw(45) << "" << "------------------" << endl << endl;
			cout << setw(45) << "" << "1) Aisle" << endl;
			cout << setw(45) << "" << "2) Window" << endl;
			cout << setw(45) << "" << "3) Center" << endl << endl;
			cout << setw(45) << "" << "Enter 1, 2 or 3: ";
			cin >> seat_type;
			if (seat_type != 1 && seat_type != 2 && seat_type != 3)
			{
				system("cls");
				cout << "\n\n\n\n\n";
				cout << setw(40) << "" << "<Invalid Entry>" << endl;
				cout << setw(30) << "" << "Please enter a selection of 1, 2 or 3" << endl;

				Sleep(2000);
				system("cls");
				cout << "\n\n\n";
			}
		} while (seat_type != 1 && seat_type != 2 && seat_type != 3);
	}
	bool match = false;
	switch (flight_class)
	{
	case 1:
		match = firstClass.getSeats(num_passengers, SEAT_TYPE(seat_type - 1));
		break;
	case 2:
		match = economyClass.getSeats(num_passengers, SEAT_TYPE(seat_type - 1));
		break;
	}

	switch (match)
	{
	case 0:
		system("cls");
		cout << "\n\n\n\n\n";
		cout << setw(45) << "" << "Match not found, sorry" << endl;
		Sleep(2000);
		break;
	case 1:
		system("cls");
		cout << "\n\n\n\n\n";
		cout << setw(45) << "" << "Seats assigned" << endl;
		Sleep(2000);
		break;
	}
}

void ReservationSystem::showSeating()
{
	firstClass.showSeats();
	economyClass.showSeats();
	cout << endl;
	cout << setw(40) << "" << "<Press Any Key to Continue>  ";
	system("pause > nul");
}

void ReservationSystem::quit()
{
	cout << "\n\n\n\n";
	cout << setw(45) << "" << "Have a nice day  ";
	Sleep(2000);
	keepRunning = false;
}


void ReservationSystem::processInput()
{
	switch (m_menu.getChoice())
	{
	case 1:
		system("cls");
		addPassenger();
		system("cls");
		break;
	case 2:
		system("cls");
		showSeating();
		system("cls");
		break;
	case 3:
		system("cls");
		quit();
		system("cls");
		break;
	}
}

bool ReservationSystem::getInput()
{
	if (m_menu.getMainMenuInput(m_menu))
		return true;
	else
		return false;
}


void ReservationSystem::run()
{
	do
	{
		if (getInput())
			processInput();
	} while (keepRunning == true);
}