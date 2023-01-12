#pragma once

//there are structures that are used for communication-->Globals

class Controls {
private:
	bool bHealth;
	bool bArmor;
	bool bAmmo;
	bool bRecoil;

public:
	bool updateUI;
	Controls() {
		bHealth = false;
		bArmor = false;
		bAmmo = false;
		bRecoil = false;
		updateUI = false;

	}

	void Enable(int id);
	void Disable(int id);
	bool getStatus(int id);
};