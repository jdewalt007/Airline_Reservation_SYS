#include <iomanip>
#include <iostream>
#include "FirstClass.h"

using std::cout;
using std::setw;
using std::endl;

First::First()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			seats[i][j] = false;
		}
	}
	left = 20;
}

bool First::getSeats(int number, SEAT_TYPE type)
{
	switch (type)
	{
	case WINDOW:
		return Window(number);
		break;
	case AISLE:
		return Aisle(number);
		break;
	}
}

bool First::Window(int number)
{
	switch (number)
	{
	case 1:
		for (int i = 0; i < 5; i++)
		{
			if (seats[i][0] == false)
			{
				seats[i][0] = true;
				left--;
				return true;
			}
			else
				if (seats[i][3] == false)
				{
					seats[i][3] = true;
					left--;
					return true;
				}
		}
		break;
	case 2:
		for (int i = 0; i < 5; i++)
		{
			if (seats[i][0] + seats[i][1] == 0)
			{
				seats[i][0] = true;
				seats[i][1] = true;
				left -= 2;
				return true;
			}
			else
				if (seats[i][2] + seats[i][3] == 0)
				{
					seats[i][2] = true;
					seats[i][3] = true;
					left -= 2;
					return true;
				}
		}
		break;
	}
	return false;
}

bool First::Aisle(int number)
{
	switch (number)
	{
	case 1:
		for (int i = 0; i < 5; i++)
		{
			if (seats[i][1] == false)
			{
				seats[i][1] = true;
				left--;
				return true;
			}
			else
				if (seats[i][2] == false)
				{
					seats[i][2] = true;
					left--;
					return true;
				}
		}
		break;
	case 2:
		for (int i = 0; i < 5; i++)
		{
			if (seats[i][0] + seats[i][1] == 0)
			{
				seats[i][0] = true;
				seats[i][1] = true;
				left -= 2;
				return true;
			}
			else
				if (seats[i][1] + seats[i][2] == 0)
				{
					seats[i][1] = true;
					seats[i][2] = true;
					left -= 2;
					return true;
				}
				else
					if (seats[i][2] + seats[i][3] == 0)
					{
						seats[i][2] = true;
						seats[i][3] = true;
						left -= 2;
						return true;
					}
		}
		break;
	}
	return false;
}


int First::seatsLeft()
{
	return left;
}


void First::showSeats()
{
	cout << "\n\n\n";
	cout << setw(48) << "" << "First class" << endl;
	cout << setw(38) << "" << "X - is taken, O - available" << endl << endl;
	cout << setw(47) << "" << "A B       D E" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << setw(43) << "" << i + 1 << " | ";
		for (int j = 0; j < 2; j++)
		{
			if (seats[i][j]) cout << "X "; else cout << "O ";
		}
		cout << "|   | ";
		for (int j = 2; j < 4; j++)
		{
			if (seats[i][j]) cout << "X "; else cout << "O ";
		}
		cout << "|\n";
	}
}