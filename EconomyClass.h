#pragma once
#include"Type.h"

class Economy
{
	public:
		Economy();
		virtual ~Economy();
		bool getSeats(int, SEAT_TYPE);
		int seatsLeft();
		void showSeats();
	private:
		bool Window(int);
		bool Aisle(int);
		bool Center(int);

		bool seats[30][6];
		int left;

};