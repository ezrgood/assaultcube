#include "Globals.h"
#include "stdafx.h"

void Controls::Enable(int id) {
	switch (id)
	{
		bHealth = true;
		break;
	}
}
void Controls::Disable(int id) {
	switch (id)
	{

		bHealth = false;
		break;
	}
}
bool Controls::getStatus(int id) {
	switch (id)
	{

		return bHealth;
		break;

	}
}