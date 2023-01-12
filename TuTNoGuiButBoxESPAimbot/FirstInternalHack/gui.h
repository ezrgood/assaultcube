#pragma once
#include <iostream>




struct Vector3 { float x, y, z; };
void printVector(const Vector3& v) {
	std::cout << "\r X, " << v.x << " Y, " << v.y << " Z, " << v.z << "" << std::flush;
}


bool bAmmo = false, bRecoil = false, bArmor = false, bHealth = false, bCoords = false, bKill = false, bKill2 = false, trigger = true, bFly = false;

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
	std::cout << "" << std::endl;
	std::cout << "[END] EXIT\n";
	std::cout << "" << std::endl;
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
		std::cout << "[NUMPAD4] No Recoil                       -> ON <-\n";
	}
	else {
		std::cout << "[NUMPAD4] No Recoil                       -> OFF <-\n";

	}
	std::cout << "" << std::endl;
	if (bKill)
		{
		std::cout << "[NUMPAD5] TDM Trigger Bot                 -> ON <-\n";
		
		}
	else {
		std::cout << "[NUMPAD5] TDM Trigger Bot                 -> OFF <-\n";

	}
	std::cout << "" << std::endl;

	if (bKill2) {
		std::cout << "[NUMPAD6] Deathmatch Trigger Bot          -> ON <-\n";
	}
	else {
		std::cout << "[NUMPAD6] Deathmatch Trigger Bot          -> OFF <-\n";

	}
	std::cout << "" << std::endl;
	if (bCoords) {

		std::cout << "[NUMPAD7] Cords                           -> ON <-\n";
		
	}
	else {

		std::cout << "[NUMPAD7] Cords                           -> OFF <-\n";
	}
	std::cout << "" << std::endl;
	if (bFly) {

		std::cout << "[NUMPAD8] FlyHack                         -> ON <-\n";

	}
	else {

		std::cout << "[NUMPAD8] FlyHack                         -> OFF <-\n";
	}
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	
}