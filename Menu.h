#pragma once

class Menu
{
	public:
		Menu();
		virtual ~Menu();

		bool getMainMenuInput(Menu&);
		int getChoice();


	private:
		int choice = 0;

};