#include "stdafx.h"

void GUI() {
	system("cls");
	SetConsoleTitle(L"Death2u");

	std::cout << " 	$$$$$$$\\                         $$\\     $$\\        $$$$$$\\ \n";
	std::cout << " 	$$  __$$\\                        $$ |    $$ |      $$  __$$\\ \n";
	std::cout << " 	$$ |  $$ | $$$$$$\\     $$$$$$\\ $$$$$$\\   $$$$$$$\\  \\__/  $$| $$\\  $$\\ \n";
	std::cout << " 	$$ |  $$ | $$ __$$\\    \\____$$\\\\_$$  _|  $$ __$$\\   $$$$$$  |$$ | $$ | \n";
	std::cout << " 	$$ |  $$ | $$$$$$$$ |  $$$$$$$ | $$ |    $$ | $$ | $$  ____/ $$ | $$ | \n";
	std::cout << " 	$$ |  $$ | $$   ____| $$  __$$ | $$ |$$\\ $$ | $$ | $$ |      $$ | $$ | \n";
	std::cout << " 	$$$$$$$ |  \\$$$$$$$\\  \\$$$$$$$ | \\$$$$ | $$ | $$ | $$$$$$$$\\ \\$$$$$$ | \n";
	std::cout << " 	\\_______ /  \\_______|  \\_______ | \\____/ \\__| \\__| \\________| \\______/ \n";
	std::cout << "#####################################################################################\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	if (bHealth) {
		std::cout << "[NUMPAD1] Godmode                         -> ON <-\n";
	}
	else {
		std::cout << "[NUMPAD1] Godmode                         -> OFF <-\n";
	}
	std::cout << "" << std::endl;

	if (bAmmo) {
		std::cout << "[NUMPAD2] Infinite Ammo                   -> ON <-\n";
	}
	else {
		std::cout << "[NUMPAD2] Infinite Ammo                   -> OFF <-\n";
	}

	std::cout << "" << std::endl;

	if (bArmor) {
		std::cout << "[NUMPAD3] Infinite Armor                  -> ON <-\n";
	}
	else {
		std::cout << "[NUMPAD3] Infinite Armor                  -> OFF <-\n";
	}
	std::cout << "" << std::endl;

	if (bRecoil) {
		std::cout << "[NUMPAD5] No Recoil                       -> ON <-\n";
	}
	else {
		std::cout << "[NUMPAD5] No Recoil                       -> OFF <-\n";

	}
	std::cout << "" << std::endl;
	std::cout << "[INSERT] EXIT\n";
}