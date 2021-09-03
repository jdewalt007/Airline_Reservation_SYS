#pragma once
#include "Type.h"

class First
{
	public:
		First();
		bool getSeats(int, SEAT_TYPE);
		int seatsLeft();
		void showSeats();
	private:
		bool Window(int);
		bool Aisle(int);

		bool seats[5][4];
		int left;
};