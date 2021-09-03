#pragma once
#include "Menu.h"
#include "EconomyClass.h"
#include "FirstClass.h"
#include "Type.h"


class ReservationSystem
{
	public:
		ReservationSystem();
		virtual ~ReservationSystem();

		bool getInput();
		void processInput();
		void run();
		void addPassenger();
		void showSeating();
		void quit();



	private:
		Menu m_menu;
		Economy economyClass;
		First firstClass;
		bool keepRunning = true;
};