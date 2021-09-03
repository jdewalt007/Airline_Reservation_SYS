#include <iomanip>
#include <iostream>
#include "EconomyClass.h"

using std::cout;
using std::setw;
using std::endl;

Economy::Economy()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			seats[i][j] = false;
		}
	}
	left = 180;
}

Economy::~Economy()
{

}

bool Economy::getSeats(int number, SEAT_TYPE type)
{
	switch (type)
	{
	case WINDOW:
		return Window(number);
		break;
	case AISLE:
		return Aisle(number);
		break;
	case CENTER:
		return Center(number);
		break;
	}
}

bool Economy::Window(int number)
{
	switch (number)
	{
	case 1:
		for (int i = 0; i < 30; i++)
		{
			if (seats[i][0] == false)
			{
				seats[i][0] = true;
				left--;
				return true;
			}
			else
				if (seats[i][5] == false)
				{
					seats[i][5] = true;
					left--;
					return true;
				}
		}
		break;
	case 2:
		for (int i = 0; i < 30; i++)
		{
			if (seats[i][0] + seats[i][1] == 0)
			{
				seats[i][0] = true;
				seats[i][1] = true;
				left -= 2;
				return true;
			}
			else
				if (seats[i][4] + seats[i][5] == 0)
				{
					seats[i][4] = true;
					seats[i][5] = true;
					left -= 2;
					return true;
				}
		}
		break;
	case 3:
		for (int i = 0; i < 30; i++)
		{
			if (seats[i][0] + seats[i][1] + seats[i][2] == 0)
			{
				seats[i][0] = true;
				seats[i][1] = true;
				seats[i][2] = true;
				left -= 3;
				return true;
			}
			else
				if (seats[i][3] + seats[i][4] + seats[i][5] == 0)
				{
					seats[i][3] = true;
					seats[i][4] = true;
					seats[i][5] = true;
					left -= 3;
					return true;
				}
		}
		break;
	}
	return false;
}

bool Economy::Center(int number)
{
	switch (number)
	{
	case 1:
		for (int i = 0; i < 30; i++)
		{
			if (seats[i][1] == false)
			{
				seats[i][1] = true;
				left--;
				return true;
			}
			else
				if (seats[i][4] == false)
				{
					seats[i][4] = true;
					left--;
					return true;
				}
		}
		break;
	case 2:
		for (int i = 0; i < 30; i++)
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
					if (seats[i][3] + seats[i][4] == 0)
					{
						seats[i][3] = true;
						seats[i][4] = true;
						left -= 2;
						return true;
					}
					else
						if (seats[i][4] + seats[i][5] == 0)
						{
							seats[i][4] = true;
							seats[i][5] = true;
							left -= 2;
							return true;
						}
		}
		break;
	case 3:
		for (int i = 0; i < 30; i++)
		{
			if (seats[i][0] + seats[i][1] + seats[i][2] == 0)
			{
				seats[i][0] = true;
				seats[i][1] = true;
				seats[i][2] = true;
				left -= 3;
				return true;
			}
			else
				if (seats[i][3] + seats[i][4] + seats[i][5] == 0)
				{
					seats[i][3] = true;
					seats[i][4] = true;
					seats[i][5] = true;
					left -= 3;
					return true;
				}
		}
		break;
	}
	return false;
}

bool Economy::Aisle(int number)
{
	switch (number)
	{
	case 1:
		for (int i = 0; i < 30; i++)
		{
			if (seats[i][2] == false)
			{
				seats[i][2] = true;
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
		for (int i = 0; i < 30; i++)
		{
			if (seats[i][1] + seats[i][2] == 0)
			{
				seats[i][1] = true;
				seats[i][2] = true;
				left -= 2;
				return true;
			}
			else
				if (seats[i][3] + seats[i][4] == 0)
				{
					seats[i][3] = true;
					seats[i][4] = true;
					left -= 2;
					return true;
				}
		}
		break;
	case 3:
		for (int i = 0; i < 30; i++)
		{
			if (seats[i][0] + seats[i][1] + seats[i][2] == 0)
			{
				seats[i][0] = true;
				seats[i][1] = true;
				seats[i][2] = true;
				left -= 3;
				return true;
			}
			else
				if (seats[i][3] + seats[i][4] + seats[i][5] == 0)
				{
					seats[i][3] = true;
					seats[i][4] = true;
					seats[i][5] = true;
					left -= 3;
					return true;
				}
		}
		break;
	}
	return false;
}

int Economy::seatsLeft()
{
	return left;
}

void Economy::showSeats()
{
	cout << "\n\n\n";
	cout << setw(48) << "" << "Economy class" << endl;
	cout << setw(38) << "" << "X - is taken, O - available" << endl << endl;
	cout << setw(46) << "" << "A B C     D E F" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << setw(42) << "" << setw(2) << i + 1 << " " << "|";
		for (int j = 0; j < 3; j++)
		{
			if (seats[i][j]) cout << "X "; else cout << "O ";
		}
		cout << "| |";
		for (int j = 3; j < 6; j++)
		{
			if (seats[i][j]) cout << " X"; else cout << " O";
		}
		cout << "|\n";
	}
}