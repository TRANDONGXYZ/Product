#include "function.h"

int main()
{
	int selection;
	Nocursortype();
	FixConsoleWindow();
	goto New;

New:;
	selection = Display();

	switch (selection)
	{
	case 2:
		goto Watch;
	case 3:
		goto Calander;
	case 4:
		goto Quit;
	}

Watch:;
	selection = Watch();
	if (selection == 1)
		goto New;
	else
		goto Calander;

Calander:;
	Lich();
	selection = Selection_Calander();
	if (selection == 1)
		goto New;
	else
		goto Watch;

Quit:;
	selection = Ask();
	if (selection == 5)
	{
		gotoxy(0, 20);
		exit(1);
	}
	else
		goto New;
}