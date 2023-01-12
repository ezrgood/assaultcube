// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <iostream>
#include "mem.h"
#include "class.h"
#include "hook.h"
#include "glDraw.h"
#include "gltext.h"
#include "esp.h"

uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");

bool bAmmo = false, bRecoil = false, bArmor = false, bHealth = false, bCoords = false, bKill = false, bKill2 = false, trigger = true, bFly = false;

typedef ent* (__cdecl* tGetCrossHairEnt)();
tGetCrossHairEnt GetCrossHairEnt = nullptr;

typedef BOOL(__stdcall* twglSwapBuffers) (HDC hDc);
twglSwapBuffers owglSwapBuffers;
twglSwapBuffers wglSwapBuffersGateway;

ent* localPlayerPtr{ nullptr };

GL::Font glFont;
const int FONT_HEIGHT = 15;
const int FONT_WIDTH = 9;



ESP esp;

void Draw()
{
	HDC currentHDC = wglGetCurrentDC();

	if (!glFont.bBuilt || currentHDC != glFont.hdc)
	{
		glFont.Build(FONT_HEIGHT);
	}

	GL::SetupOrtho();

	esp.Draw(glFont);

	GL::RestoreGL();
}




BOOL __stdcall hkwglSwapBuffers(HDC hDc)
{
	
	moduleBase = (uintptr_t)GetModuleHandle(NULL);	
	GetCrossHairEnt = (tGetCrossHairEnt)(moduleBase + 0x607c0);	
	if (GetAsyncKeyState(VK_NUMPAD1) & 1)
	{
		bHealth = !bHealth;
		
	}

	if (GetAsyncKeyState(VK_NUMPAD2) & 1)
	{
		bAmmo = !bAmmo;
		
	}

	if (GetAsyncKeyState(VK_NUMPAD3) & 1)
	{
		bArmor = !bArmor;
		
	}


	if (GetAsyncKeyState(VK_NUMPAD4) & 1)
	{
		bRecoil = !bRecoil;
		

		if (bRecoil)
		{
			mem::Nop((BYTE*)(moduleBase + 0x63786), 10);
		}
		else
		{
			//50 8D 4C 24 1C 51 8B CE FF D2 the original stack setup and call
			mem::Patch((BYTE*)(moduleBase + 0x63786), (BYTE*)"\x50\x8D\x4C\x24\x1C\x51\x8B\xCE\xFF\xD2", 10);
		}
	}

	if (GetAsyncKeyState(VK_NUMPAD5) & 1)
	{
		bKill = !bKill;
		
	}

	if (GetAsyncKeyState(VK_NUMPAD9) & 1)
	{
		bKill2 = !bKill2;
		
	}

	if (GetAsyncKeyState(VK_NUMPAD7) & 1)
	{
		bCoords = !bCoords;
		

	}
	if (GetAsyncKeyState(VK_NUMPAD8) & 1)
	{
		bFly = !bFly;
		

	}

	
	localPlayerPtr = *(ent**)(moduleBase + 0x10F4F4);
	ent* crossHairEnt = GetCrossHairEnt();
	
	if (localPlayerPtr)
	{

		if (bHealth)
		{
			localPlayerPtr->health = 1337;
			
		}
		if (bAmmo)
		{
			localPlayerPtr->currWeapon->ammoClip->ammo = 500;
		}
		if (bArmor)
		{
			localPlayerPtr->armor = 316;
		}
		if (bCoords)
		{
			//Vector3 v(localPlayerPtr->pos);
			//printVector(v);
		}
		if (bFly)
		{
			localPlayerPtr->noClip = 11;
			localPlayerPtr->state = 5;
		}
		else
		{
			localPlayerPtr->noClip = 0;
			localPlayerPtr->state = 0;
		}
		if (bKill)
		{

			if (crossHairEnt)
			{
				if (localPlayerPtr->team != crossHairEnt->team)
				{
					localPlayerPtr->bAttacking = 1;
				}
			}
			else
			{
				localPlayerPtr->bAttacking = 0;
			}


		}
		if (bKill2)
		{
			if (crossHairEnt)
			{
				if (localPlayerPtr->team = crossHairEnt->team)
				{
					localPlayerPtr->bAttacking = 1;
				}

				if (localPlayerPtr->team != crossHairEnt->team)
				{
					localPlayerPtr->bAttacking = 1;
				}
				else
				{
					localPlayerPtr->bAttacking = 0;
				}
			}
		}

	}
	Draw();
	
	return wglSwapBuffersGateway(hDc);
}

	





DWORD WINAPI HackThread(HMODULE hModule)
{
	//Create Console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);		

	std::cout << "Hooked\n";
	

	

	Hook SwapBuffersHook("wglSwapBuffers", "opengl32.dll", (BYTE*)hkwglSwapBuffers, (BYTE*)&wglSwapBuffersGateway, 5);
	SwapBuffersHook.Enable();
	
	
	

	Sleep(20000);
	//SwapBuffersHook.Disable();
	fclose(f);
	FreeConsole();	
	//FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}