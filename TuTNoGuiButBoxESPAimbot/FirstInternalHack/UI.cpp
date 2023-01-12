#include "Globals.h"
#include "stdafx.h"


void EnableDisable(bool b) {
	if (b)
		std::cout << color(green) << "Enabled\n";
	else
		std::cout << color(red) << "Disabled\n";
}
CW_COLORS a;
CW_COLORS b;
int colorc;


void UserInterface(Controls* ctrl) {
	while (true) {
		a = (enableRandomColor ? randomColor() : magenta);
		b = (enableRandomColor ? randomColor() : green);
		std::cout << color(green) << "Version 1.0\n\n";

		if (ctrl->scanEntity) {
			getEntityInfo();
			ctrl->scanEntity = false;
		}
		
		std::cout << color(yellow) << "Health[" << color(magenta) << "F4" << color(yellow) << "]:"; EnableDisable(ctrl->getStatus(maxHealth)); std::cout << "\n";
		
		while (true) {  //THE UGLIEST IMPLEMENTATION OF ANTIFLICKERING

			if (ctrl->updateUI) {
				Sleep(10);
				break;
			}
		}
		ctrl->updateUI = false;
		system("cls");
	}
}